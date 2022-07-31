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
            HV4DHelpers::GetActivationFactory(
                L"C:/Users/rebek/source/DUALITY/x64/Debug/HV4DCmdShell/HV4DCmdShell.dll",
                L"HV4DCmdShell.HV4DCommandLine");

        oCmdShell = oActivationFactory.ActivateInstance<HV4DDUALITY::HV4DEnvironment::IHV4DCmdShell>();

        oCmdShell.HV4DNewShell();
        
        return;

    }

    void ContainerUI::LoadInputBuffer()
    {
        winrt::Windows::Foundation::IActivationFactory oActivationFactory =
            HV4DHelpers::GetActivationFactory(
                L"C:/Users/rebek/source/DUALITY/x64/Debug/HV4DCoordST/HV4DCoordST.dll",
                L"HV4DCoordST.HV4DResourceManager");

        oInputBuffer = oActivationFactory.ActivateInstance<HV4DDUALITY::HV4DEnvironment::IHV4DInputBuffer>();

        oInputBuffer.HV4DLoadInputBufferFromFile(L"");
        
        return;

    }

    void ContainerUI::LoadPipeline()
    {
        winrt::Windows::Foundation::IActivationFactory oObj =
            HV4DHelpers::GetActivationFactory(
                L"C:/Users/rebek/source/DUALITY/x64/Debug/PeregrineX12/PeregrineX12.dll",
                L"PeregrineX12.HV4DPeregrineX12");

        oPipeline = oObj.ActivateInstance<HV4DDUALITY::HV4DTensors::IHV4DPipeline>();

        oPipeline.HV4DOnInit(ContainerView());

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
        oPipeline.HV4DOnRender();

        return;

    }

}