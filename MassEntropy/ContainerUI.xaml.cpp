#include "pch.h"
#include "ContainerUI.xaml.h"
#if __has_include("ContainerUI.g.cpp")
#include "ContainerUI.g.cpp"
#endif

using namespace std;

using namespace winrt;

using namespace winrt::Windows;
using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MassEntropy::implementation
{
    ContainerUI::ContainerUI()
    {
        InitializeComponent();
        
        return;

    }

    void winrt::MassEntropy::implementation::ContainerUI::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        //LoadShell();

        //LoadInputBuffer();

        LoadPipeline();

        return;

    }

    void ContainerUI::LoadShell()
    {
        winrt::Windows::Foundation::IActivationFactory oActivationFactory =
            HV3DHelpers::GetActivationFactory(
                L"C:/Users/rebek/source/DUALITY/x64/Debug/HV3DCmdShell/HV3DCmdShell.dll",
                L"HV3DCmdShell.HV3DCommandLine");

        oCmdShell = oActivationFactory.ActivateInstance<HV3DDUALITY::HV3DEnvironment::IHV3DCmdShell>();

        oCmdShell.HV3DNewShell();
        
        return;

    }

    void ContainerUI::LoadInputBuffer()
    {
        winrt::Windows::Foundation::IActivationFactory oActivationFactory =
            HV3DHelpers::GetActivationFactory(
                L"C:/Users/rebek/source/DUALITY/x64/Debug/HV3DCoordST/HV3DCoordST.dll",
                L"HV3DCoordST.HV3DResourceManager");

        oInputBuffer = oActivationFactory.ActivateInstance<HV3DDUALITY::HV3DEnvironment::IHV3DInputBuffer>();

        oInputBuffer.HV3DLoadInputBufferFromFile(L"");
        
        return;

    }

    void ContainerUI::LoadPipeline()
    {
        winrt::Windows::Foundation::IActivationFactory oObj =
            HV3DHelpers::GetActivationFactory(
                L"C:/Users/rebek/source/DUALITY/x64/Debug/PeregrineX12/PeregrineX12.dll",
                L"PeregrineX12.HV3DPeregrineX12");

        oPipeline = oObj.ActivateInstance<HV3DDUALITY::HV3DTensors::IHV3DPipeline>();

        oPipeline.HV3DOnInit(ContainerView());

        RegisterTickEvent();

        return;

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
        oPipeline.HV3DOnRender();

        return;

    }

}