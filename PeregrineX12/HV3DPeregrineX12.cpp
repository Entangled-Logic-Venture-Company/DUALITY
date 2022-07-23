#include "pch.h"
#include "HV3DPeregrineX12.h"
#if __has_include("HV3DPeregrineX12.g.cpp")
#include "HV3DPeregrineX12.g.cpp"
#endif

using namespace DirectX;

using namespace winrt;

using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::PeregrineX12::implementation
{
	void HV3DPeregrineX12::HV3DOnInit(Windows::Foundation::IInspectable panel)
	{
		feature_level = D3D_FEATURE_LEVEL_12_0;

		unknPanel = panel;

		xamlSwapChainPanel = unknPanel.as<Microsoft::UI::Xaml::Controls::SwapChainPanel>();
				
		auto oNativeSwapChainPanel{ xamlSwapChainPanel.as<::ISwapChainPanelNative>()};
		nativeSwapChainPanel = oNativeSwapChainPanel;

		HV3DLoadPipeline();

		HV3DLoadAssets();

		return;

	}

	void HV3DPeregrineX12::HV3DOnUpdate()
	{


		return;

	}

	void HV3DPeregrineX12::HV3DOnRender()
	{
		HV3DPopulateCommandList();
		
		*d3dCommandLists = d3dCommandList;
		d3dCommandQueue->ExecuteCommandLists(
			1, 
			d3dCommandLists);

		dxgiSwapChain->Present(1, 0);

		HV3DWaitForPreviousFrame();
		
		return;

	}

	void HV3DPeregrineX12::HV3DOnDestroy()
	{
		HV3DWaitForPreviousFrame();

		CloseHandle(hFenceEvent);

		return;

	}

	void HV3DPeregrineX12::HV3DLoadPipeline()
	{
		HRESULT hr = S_OK;

#if defined(_DEBUG)
		{
			hr = D3D12GetDebugInterface(
				__uuidof(ID3D12Debug),
				(void**)&d3dDebugController);

			d3dDebugController->EnableDebugLayer();
		}
#endif

		hr = CreateDXGIFactory2(
			DXGI_CREATE_FACTORY_DEBUG,
			__uuidof(IDXGIFactory7),
			(void**)&dxgiFactory);

		IDXGIAdapter1* oAdaptor;
		hr = dxgiFactory->EnumAdapters1(
			1,
			&oAdaptor);

		hr = oAdaptor->QueryInterface(
			__uuidof(IDXGIAdapter4),
			(void**)&dxgiAdapter);

		hr = D3D12CreateDevice(
			dxgiAdapter,
			D3D_FEATURE_LEVEL_12_0,
			_uuidof(ID3D12Device),
			(void**)&d3dDevice );

		hr = d3dDevice->CreateCommandQueue(
			&d3dQueueDesc,
			__uuidof(ID3D12CommandQueue),
			(void**)&d3dCommandQueue);
		
		IDXGISwapChain1** oSwapChain = new IDXGISwapChain1*();
		hr = dxgiFactory->CreateSwapChainForComposition(
			d3dCommandQueue,
			&dxgiSwapChainDesc,
			NULL,
			oSwapChain);

		hr = (*oSwapChain)->QueryInterface(
			__uuidof(IDXGISwapChain),
			(void**)&dxgiSwapChainXaml);

		hr = nativeSwapChainPanel.get()->SetSwapChain(
			dxgiSwapChainXaml);

		hr = (*oSwapChain)->QueryInterface(
			__uuidof(IDXGISwapChain4),
			(void**)&dxgiSwapChain);

		frame_index = dxgiSwapChain->GetCurrentBackBufferIndex();

		hr = d3dDevice->CreateDescriptorHeap(
			&d3dRTVHeapDesc, 
			__uuidof(ID3D12DescriptorHeap),
			(void**)&d3dRTVHeap);

		rtv_descriptor_size = d3dDevice->GetDescriptorHandleIncrementSize(
			D3D12_DESCRIPTOR_HEAP_TYPE_RTV);		

		CD3DX12_CPU_DESCRIPTOR_HANDLE oD3DXRTVHandle(
			d3dRTVHeap->GetCPUDescriptorHandleForHeapStart());

		for (UINT n = 0; n < frame_count; n++)
		{
			hr = dxgiSwapChain->GetBuffer(
				n,
				__uuidof(ID3D12Resource), 
				(void**)&d3dRenderTargets[n]);

			d3dDevice->CreateRenderTargetView(
				d3dRenderTargets[n],
				&d3dRenderTargetViewDescription,
				oD3DXRTVHandle);
			
			oD3DXRTVHandle.Offset(
				1,
				rtv_descriptor_size); 
		
		}

		oD3DXRTVHandle.Offset(
			-2,
			rtv_descriptor_size);

		d3dRTVHandle = oD3DXRTVHandle;

		hr = d3dDevice->CreateCommandAllocator(
			D3D12_COMMAND_LIST_TYPE_BUNDLE,
			__uuidof(ID3D12CommandAllocator),
			(void**)&d3dCommandAllocator);

		return;

	}

	void HV3DPeregrineX12::HV3DLoadAssets()
	{
		HRESULT hr = S_OK;

		hr = D3D12SerializeRootSignature(
			&d3dRootSignatureDesc, 
			D3D_ROOT_SIGNATURE_VERSION_1, 
			&d3dSignature, 
			&d3dError);
						
		hr = d3dDevice->CreateRootSignature(
			0, 
			d3dSignature->GetBufferPointer(), 
			d3dSignature->GetBufferSize(), 
			__uuidof(ID3D12RootSignature),
			(void**)&d3dRootSignature);

#if defined(_DEBUG)
			UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
			UINT compileFlags = 0;
#endif

			hr = D3DCompileFromFile(
				L"shaders.hlsl", 
				nullptr, 
				nullptr, 
				"VSMain", 
				"vs_5_0", 
				compileFlags, 
				0, 
				&d3dVertexShader, 
				nullptr);
			
			hr = D3DCompileFromFile(
				L"shaders.hlsl",
				nullptr, 
				nullptr, 
				"PSMain", 
				"ps_5_0", 
				compileFlags, 
				0, 
				&d3dPixelShader, 
				nullptr);

		d3dPSODesc.VS = { reinterpret_cast<UINT8*>(d3dVertexShader->GetBufferPointer()), d3dVertexShader->GetBufferSize() };
		d3dPSODesc.PS = { reinterpret_cast<UINT8*>(d3dPixelShader->GetBufferPointer()), d3dPixelShader->GetBufferSize() };
		d3dPSODesc.DS = { nullptr };
		d3dPSODesc.HS = { nullptr };
		d3dPSODesc.GS = { nullptr };

		hr = d3dDevice->CreateGraphicsPipelineState(
			&d3dPSODesc, 
			__uuidof(ID3D12PipelineState),
			(void**)&d3dPipelineState);

		hr = d3dDevice->CreateCommandList(
			0, 
			D3D12_COMMAND_LIST_TYPE_DIRECT, 
			d3dCommandAllocator, 
			d3dPipelineState, 
			__uuidof(ID3D12GraphicsCommandList5),
			(void**)&d3dCommandList);

		hr = d3dCommandList->Close();

		Vertex oTriangleVertices[] =
		{
			{ { 0.0f, 0.25f * aspect_ratio, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
			{ { 0.25f, -0.25f * aspect_ratio, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
			{ { -0.25f, -0.25f * aspect_ratio, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
		};

		const UINT vertex_buffer_size = sizeof(oTriangleVertices);

		// Note: using upload heaps to transfer static data like vert buffers is not 
		// recommended. Every time the GPU needs it, the upload heap will be marshalled 
		// over. Please read up on Default Heap usage. An upload heap is used here for 
		// code simplicity and because there are very few verts to actually transfer.
				
		d3dResourceDesc = CD3DX12_RESOURCE_DESC::Buffer(vertex_buffer_size);

		hr = d3dDevice->CreateCommittedResource(
			&d3dHeapProps,
			D3D12_HEAP_FLAG_NONE,
			&d3dResourceDesc,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			__uuidof(ID3D12Resource),
			(void**)&d3dVertexBuffer);

		UINT8* vertex_data_begin;
		
		CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
		
		hr = d3dVertexBuffer->Map(
			0, 
			&readRange, 
			(void**)&vertex_data_begin);
		
		memcpy(vertex_data_begin, oTriangleVertices, sizeof(oTriangleVertices));
		
		d3dVertexBuffer->Unmap(0, nullptr);

		d3dVertexBufferView.BufferLocation = d3dVertexBuffer->GetGPUVirtualAddress();
		d3dVertexBufferView.StrideInBytes = sizeof(Vertex);
		d3dVertexBufferView.SizeInBytes = vertex_buffer_size;

		hr = d3dDevice->CreateFence(
			0, 
			D3D12_FENCE_FLAG_NONE, 
			__uuidof(ID3D12Fence),
			(void**)&d3dFence);

		fence_value = 1;

		hFenceEvent = CreateEvent(
			nullptr, 
			FALSE, 
			FALSE, 
			nullptr);

		if (hFenceEvent == nullptr)
		{
			winrt::throw_last_error();
		}

		HV3DWaitForPreviousFrame();

		return;

	}

	void HV3DPeregrineX12::HV3DPopulateCommandList()
	{
		HRESULT hr = S_OK;

		hr = d3dCommandAllocator->Reset();

		hr = d3dCommandList->Reset(
			d3dCommandAllocator, 
			d3dPipelineState);

		d3dCommandList->SetGraphicsRootSignature(d3dRootSignature);
		d3dCommandList->RSSetViewports(1, &d3dViewport);
		d3dCommandList->RSSetScissorRects(1, &d3dScissorRect);

		d3dResourceBarrier = CD3DX12_RESOURCE_BARRIER::Transition(
			d3dRenderTargets[frame_index], 
			D3D12_RESOURCE_STATE_PRESENT, 
			D3D12_RESOURCE_STATE_RENDER_TARGET );

		d3dCommandList->ResourceBarrier(1, &d3dResourceBarrier);

		d3dRTVHandle = CD3DX12_CPU_DESCRIPTOR_HANDLE (
			d3dRTVHeap->GetCPUDescriptorHandleForHeapStart(), 
			frame_index, 
			rtv_descriptor_size );
		
		d3dCommandList->OMSetRenderTargets(
			1, 
			&d3dRTVHandle, 
			FALSE, 
			nullptr );

		const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };

		d3dCommandList->ClearRenderTargetView(d3dRTVHandle, clearColor, 0, nullptr);
		d3dCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		d3dCommandList->IASetVertexBuffers(0, 1, &d3dVertexBufferView);
		d3dCommandList->DrawInstanced(3, 1, 0, 0);

		d3dResourceBarrier = CD3DX12_RESOURCE_BARRIER::Transition(
			d3dRenderTargets[frame_index], 
			D3D12_RESOURCE_STATE_RENDER_TARGET, 
			D3D12_RESOURCE_STATE_PRESENT );

		d3dCommandList->ResourceBarrier(1, &d3dResourceBarrier);

		hr = d3dCommandList->Close();

		return;

	}

	void HV3DPeregrineX12::HV3DWaitForPreviousFrame()
	{
		HRESULT hr = S_OK;

		const UINT64 fence = fence_value;

		hr = d3dCommandQueue->Signal(
			d3dFence, 
			fence);
		
		fence_value++;

		if (d3dFence->GetCompletedValue() < fence)
		{
			hr = d3dFence->SetEventOnCompletion(
				fence, 
				hFenceEvent);
		
			WaitForSingleObject(
				hFenceEvent,
				INFINITE );
		
		}

		frame_index = dxgiSwapChain->GetCurrentBackBufferIndex();

		return;

	}

}
