#include "pch.h"

#include "HV4DPixels.h"


namespace PeregrineX12
{
	HV4DShader HV4DPixels::HV4DLoadShaderResource(std::wstring)
	{
		HRESULT hr = S_OK;

#if defined(_DEBUG)
		UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
		UINT compileFlags = 0;
#endif

		hr = D3D12SerializeRootSignature(
			&d3dRootSignatureDesc,
			D3D_ROOT_SIGNATURE_VERSION_1,
			d3dSignature,
			d3dError);

		hr = (*d3dDevice9)->CreateRootSignature(
			0,
			(*d3dSignature)->GetBufferPointer(),
			(*d3dSignature)->GetBufferSize(),
			__uuidof(ID3D12RootSignature),
			(void**)d3dRootSignature);

		hr = D3DCompileFromFile(
			L"C:\\Users\\rebek\\source\\DUALITY\\PeregrineX12\\shaders.hlsl",
			nullptr,
			nullptr,
			"VSMain",
			"vs_5_0",
			compileFlags,
			0,
			d3dVertexShader,
			d3dVertexError);

		hr = D3DCompileFromFile(
			L"C:\\Users\\rebek\\source\\DUALITY\\PeregrineX12\\shaders.hlsl",
			nullptr,
			nullptr,
			"PSMain",
			"ps_5_0",
			compileFlags,
			0,
			d3dPixelShader,
			d3dPixelError);

		return;

	}

}
