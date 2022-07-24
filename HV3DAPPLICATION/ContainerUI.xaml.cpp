#include "pch.h"
#include "ContainerUI.xaml.h"
#if __has_include("ContainerUI.g.cpp")
#include "ContainerUI.g.cpp"
#endif

using namespace winrt;

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::HV3DAPPLICATION::implementation
{
    ContainerUI::ContainerUI()
    {
        InitializeComponent();
        
        return;

    }

    void winrt::HV3DAPPLICATION::implementation::ContainerUI::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        int32_t ret = 0;

        void* dllHandle = WINRT_IMPL_LoadLibraryW(
            L"C:/Users/rebek/source/DUALITY/x64/Debug/PeregrineX12/PeregrineX12.dll");

        if (!dllHandle) { throw; };

        void* pProc = WINRT_IMPL_GetProcAddress(dllHandle, "DllGetActivationFactory");
        auto DllGetActivationFactory = reinterpret_cast<int32_t(__stdcall*)(void* classId, void** factory)>(pProc);

        static const WCHAR* cname = L"PeregrineX12.HV3DPeregrineX12";
        const UINT32 cnamelen = wcslen(cname);

        HSTRING hcname = NULL;
        HSTRING_HEADER header;
        HRESULT hr = WindowsCreateStringReference(cname, cnamelen, &header, &hcname);

        com_ptr< winrt::impl::abi_t<winrt::Windows::Foundation::IActivationFactory> > oCOMActivationFactory{ nullptr };
        ret = (*DllGetActivationFactory)(&header, oCOMActivationFactory.put_void());

        com_ptr< winrt::impl::abi_t<winrt::Windows::Foundation::IUnknown> > iObj{ nullptr };
        ret = oCOMActivationFactory.get()->ActivateInstance(iObj.put_void());

        oPipeline = nullptr;
        winrt::copy_from_abi(oPipeline, iObj.as<HV3DDUALITY::HV3DView::IHV3DPipeline>());

        oPipeline.get()->HV3DOnInit(
            winrt::detach_abi(ContainerView()));

        oPipeline.get()->HV3DOnRender();

        oCOMActivationFactory.detach();

        WindowsDeleteString(hcname);

    }

}