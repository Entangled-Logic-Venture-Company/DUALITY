#pragma once

#include "HV3DPeregrineX12.g.h"

struct Vertex {
    DirectX::XMFLOAT3 position;

    DirectX::XMFLOAT4 color;
};

namespace winrt::PeregrineX12::implementation
{
    struct HV3DPeregrineX12 : HV3DPeregrineX12T<HV3DPeregrineX12>
    {
    public:
        HV3DPeregrineX12() = default;

        virtual void HV3DOnInit(winrt::Windows::Foundation::IInspectable panel);

        virtual void HV3DOnUpdate();

        virtual void HV3DOnRender();

        virtual void HV3DOnDestroy();

    private:
        D3D_FEATURE_LEVEL                               feature_level{ D3D_FEATURE_LEVEL_12_0 };
        
        Windows::Foundation::IInspectable               unknPanel{ nullptr };

        Microsoft::UI::Xaml::Controls::SwapChainPanel   xamlSwapChainPanel{ nullptr };

        winrt::com_ptr<::ISwapChainPanelNative>         nativeSwapChainPanel{ nullptr };

    private:
        void HV3DLoadPipeline();

        ID3D12Debug**                           d3dDebugController{ new ::ID3D12Debug*[1] };

        static const UINT                       frame_count{ 2 };

        UINT                                    frame_index{ 0 };

        ::IDXGIFactory7**                       dxgiFactory7{ new ::IDXGIFactory7*[1] };

        ::IDXGIAdapter4**                       dxgiAdapter4{ new ::IDXGIAdapter4*[1] };

        ::IDXGIDevice4**                        dxgiDevice4{ new ::IDXGIDevice4*[1] };

        ::IDXGISwapChain1**                     dxgiSwapChain1{ new ::IDXGISwapChain1*[1] };

        ::IDXGISwapChain4**                     dxgiSwapChain4{ new ::IDXGISwapChain4*[1] };

        ::IDXGISurface2**                       dxgiBackBuffer{ new ::IDXGISurface2*[1] };

        ::ID3D12Device9**                       d3dDevice9{ new ::ID3D12Device9*[1] };

        ::ID3D12Resource**                      d3dRenderTargets{ new ::ID3D12Resource*[frame_count] };

        D3D12_VIEWPORT d3dViewport{
            d3dViewport.TopLeftX    = 0.0f,
            d3dViewport.TopLeftY    = 0.0f,
            d3dViewport.Width       = 1920,
            d3dViewport.Height      = 1080,
            d3dViewport.MinDepth    = 0.0f,
            d3dViewport.MaxDepth    = 0.0f };
                
        D3D12_RECT d3dScissorRect{
            d3dScissorRect.left     = 0.0f,
            d3dScissorRect.top      = 0.0f,
            d3dScissorRect.right    = 1920,
            d3dScissorRect.bottom   = 1080 };

        // Pipeline Resources
        UINT                                    rtv_descriptor_size;

        D3D12_CPU_DESCRIPTOR_HANDLE*            d3dRTVHandle{ new D3D12_CPU_DESCRIPTOR_HANDLE[1] };

        ::ID3D12CommandAllocator**              d3dCommandAllocator{ new ::ID3D12CommandAllocator*[1] };

        ::ID3D12CommandQueue**                  d3dCommandQueue{ new ::ID3D12CommandQueue*[1] };

        ::ID3D12CommandList**                   d3dCommandLists{ new ::ID3D12CommandList*[1] };

        ::ID3D12GraphicsCommandList**           d3dCommandList{ new ::ID3D12GraphicsCommandList*[1] };

        D3D12_HEAP_PROPERTIES                   d3dHeapProps{ CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD) };

        ::ID3D12DescriptorHeap**                d3dRTVHeap{ new ::ID3D12DescriptorHeap*[1] };
        
        D3D12_RENDER_TARGET_VIEW_DESC d3dRenderTargetViewDescription{
        d3dRenderTargetViewDescription.Format = DXGI_FORMAT_UNKNOWN,
        d3dRenderTargetViewDescription.ViewDimension = D3D12_RTV_DIMENSION_UNKNOWN };

        D3D12_COMMAND_QUEUE_DESC d3dQueueDesc{
        d3dQueueDesc.Type       = D3D12_COMMAND_LIST_TYPE_DIRECT,
        d3dQueueDesc.Priority   = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL,
        d3dQueueDesc.Flags      = D3D12_COMMAND_QUEUE_FLAG_NONE,
        d3dQueueDesc.NodeMask   = NULL };

        DXGI_SAMPLE_DESC dxgiSampleDescription{
        dxgiSampleDescription.Count     = 1,
        dxgiSampleDescription.Quality   = 0};
        
        DXGI_SWAP_CHAIN_DESC1 dxgiSwapChainDesc{
        dxgiSwapChainDesc.Width         = 1920,
        dxgiSwapChainDesc.Height        = 1080,
        dxgiSwapChainDesc.Format        = DXGI_FORMAT_B8G8R8A8_UNORM,
        dxgiSwapChainDesc.Stereo        = false,
        dxgiSwapChainDesc.SampleDesc    = dxgiSampleDescription,
        dxgiSwapChainDesc.BufferUsage   = DXGI_USAGE_RENDER_TARGET_OUTPUT,
        dxgiSwapChainDesc.BufferCount   = frame_count,
        dxgiSwapChainDesc.Scaling       = DXGI_SCALING_STRETCH,
        dxgiSwapChainDesc.SwapEffect    = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL,
        dxgiSwapChainDesc.AlphaMode     = DXGI_ALPHA_MODE_PREMULTIPLIED,
        dxgiSwapChainDesc.Flags         = NULL };
        
        D3D12_DESCRIPTOR_HEAP_DESC d3dRTVHeapDesc{
        d3dRTVHeapDesc.Type                     = D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
        d3dRTVHeapDesc.NumDescriptors           = frame_count,
        d3dRTVHeapDesc.Flags                    = D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
        d3dRTVHeapDesc.NodeMask                 = NULL };

    private:
        void HV3DLoadAssets();

        ::ID3D12PipelineState**     d3dPipelineState{ new ID3D12PipelineState*[1] };

        D3D12_VERTEX_BUFFER_VIEW    d3dVertexBufferView{ NULL };

        D3D12_RESOURCE_DESC         d3dResourceDesc{};

        D3D12_RESOURCE_BARRIER      d3dResourceBarrier{};
        
        ::ID3D12Resource**          d3dVertexBuffer{ new ::ID3D12Resource*[frame_count] };
        
        ::ID3DBlob**                d3dVertexShader{ new ::ID3DBlob*[1] };

        ::ID3DBlob**                d3dPixelShader{ new ::ID3DBlob*[1] };

        ::ID3D12RootSignature**     d3dRootSignature{ new ::ID3D12RootSignature*[1] };

        ::ID3DBlob**                d3dSignature{ new ::ID3DBlob*[1] };
                
        ::ID3DBlob**                d3dError{ new ::ID3DBlob*[1] };

        ::ID3DBlob**                d3dVertexError{ new ::ID3DBlob*[1] };

        ::ID3DBlob**                d3dPixelError{ new ::ID3DBlob*[1] };

        ::ID3D12Fence**             d3dFence{ new ::ID3D12Fence*[1] };

        HANDLE*                     hFenceEvent{ new ::HANDLE[1] };

        UINT64                      fence_value{ NULL };

        D3D12_ROOT_SIGNATURE_DESC d3dRootSignatureDesc{
        d3dRootSignatureDesc.NumParameters          = 0,
        d3dRootSignatureDesc.pParameters            = { nullptr },
        d3dRootSignatureDesc.NumStaticSamplers      = 0,
        d3dRootSignatureDesc.pStaticSamplers        = { nullptr },
        d3dRootSignatureDesc.Flags                  = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT };

        D3D12_INPUT_ELEMENT_DESC d3dInputElementDescs[2]
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };

        D3D12_STREAM_OUTPUT_DESC d3dStreamOutputDesc{
            d3dStreamOutputDesc.pSODeclaration  = { nullptr },
            d3dStreamOutputDesc.NumEntries      = 0,
            d3dStreamOutputDesc.pBufferStrides  = { nullptr },
            d3dStreamOutputDesc.NumStrides      = 0,
            d3dStreamOutputDesc.RasterizedStream = 0 };

        D3D12_BLEND_DESC d3dBlendDesc{
            CD3DX12_BLEND_DESC(D3D12_DEFAULT) };

        D3D12_RASTERIZER_DESC d3dRasterizerDes{
            CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT) };

        D3D12_DEPTH_STENCIL_DESC d3dDepthStencilDesc{
            d3dDepthStencilDesc.DepthEnable     = FALSE,
            d3dDepthStencilDesc.DepthWriteMask  = {},
            d3dDepthStencilDesc.DepthFunc       = {},
            d3dDepthStencilDesc.StencilEnable   = FALSE,
            d3dDepthStencilDesc.StencilReadMask = {},
            d3dDepthStencilDesc.StencilWriteMask = {},
            d3dDepthStencilDesc.FrontFace       = {},
            d3dDepthStencilDesc.BackFace        = {} };

        D3D12_GRAPHICS_PIPELINE_STATE_DESC d3dPSODesc{
            d3dPSODesc.pRootSignature       = { nullptr },
            d3dPSODesc.VS                   = { nullptr },
            d3dPSODesc.PS                   = { nullptr },
            d3dPSODesc.DS                   = { nullptr },
            d3dPSODesc.HS                   = { nullptr },
            d3dPSODesc.GS                   = { nullptr },
            d3dPSODesc.StreamOutput         = d3dStreamOutputDesc,
            d3dPSODesc.BlendState           = d3dBlendDesc,
            d3dPSODesc.SampleMask           = UINT_MAX,
            d3dPSODesc.RasterizerState      = d3dRasterizerDes,
            d3dPSODesc.DepthStencilState    = d3dDepthStencilDesc,
            d3dPSODesc.InputLayout          = { nullptr, 0 },
            d3dPSODesc.IBStripCutValue      = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED,
            d3dPSODesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE,
            d3dPSODesc.NumRenderTargets     = 1,
            d3dPSODesc.RTVFormats[0]        = DXGI_FORMAT_B8G8R8A8_UNORM,
            d3dPSODesc.RTVFormats[1]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.RTVFormats[2]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.RTVFormats[3]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.RTVFormats[4]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.RTVFormats[5]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.RTVFormats[6]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.RTVFormats[7]        = DXGI_FORMAT_UNKNOWN,
            d3dPSODesc.DSVFormat            = DXGI_FORMAT_B8G8R8A8_UNORM,
            d3dPSODesc.SampleDesc           = dxgiSampleDescription,
            d3dPSODesc.NodeMask             = NULL,
            d3dPSODesc.CachedPSO            = {},
            d3dPSODesc.Flags                = D3D12_PIPELINE_STATE_FLAG_NONE };

    private:
        void HV3DPopulateCommandList();

        void HV3DWaitForPreviousFrame();

    };

}

namespace winrt::PeregrineX12::factory_implementation
{
    struct HV3DPeregrineX12 : HV3DPeregrineX12T<HV3DPeregrineX12, implementation::HV3DPeregrineX12>
    {

    };

}
