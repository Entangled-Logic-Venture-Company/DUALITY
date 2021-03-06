#include "pch.h"
#include "ContainerUI.xaml.h"
#if __has_include("ContainerUI.g.cpp")
#include "ContainerUI.g.cpp"
#endif

using namespace winrt;

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::RFiles::implementation
{
    ContainerUI::ContainerUI()
    {
        InitializeComponent();
        
        return;

    }

    void winrt::RFiles::implementation::ContainerUI::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        int32_t ret = 0;

        void* dllHandle = WINRT_IMPL_LoadLibraryW(
            L"C:/Users/rebek/source/DUALITY/x64/Debug/PeregrineX12/PeregrineX12.dll");

        if (!dllHandle) { throw; };

        void* pProc = WINRT_IMPL_GetProcAddress(dllHandle, "DllGetActivationFactory");
        auto DllGetActivationFactory = reinterpret_cast<int32_t(__stdcall*)(void* classId, void** factory)>(pProc);

        static const WCHAR* cname = L"PeregrineX12.HV4DPeregrineX12";
        const UINT32 cnamelen = (UINT32)wcslen(cname);

        HSTRING hcname = NULL;
        HSTRING_HEADER header;
        HRESULT hr = WindowsCreateStringReference(cname, cnamelen, &header, &hcname);
                
        void** unkActivationFactory = new void*[1];
        ret = (*DllGetActivationFactory)(&header, unkActivationFactory);

        Windows::Foundation::IActivationFactory oActivationFactory{ nullptr };
        winrt::copy_from_abi(oActivationFactory, *unkActivationFactory);

        HV4DPipeline = oActivationFactory.ActivateInstance<HV4DDUALITY::HV4DTensors::IHV4DPipeline>();
        
        HV4DPipeline.HV4DOnInit(
            ContainerView() );

        RegisterTickEvent();

        WindowsDeleteString(hcname);

    }

    void ContainerUI::RegisterTickEvent()
    {
        oDispatchTimer = new Microsoft::UI::Xaml::DispatcherTimer[1];

        oDispatchTimer->Interval(std::chrono::milliseconds{ 15 });

        timer_event = oDispatchTimer->Tick({ this, &ContainerUI::OnTick });
        
        oDispatchTimer->Start();

    }

    void ContainerUI::OnTick(Windows::Foundation::IInspectable const&, Windows::Foundation::IInspectable const&)
    {
        HV4DPipeline.HV4DOnRender();

        return;

    }

}