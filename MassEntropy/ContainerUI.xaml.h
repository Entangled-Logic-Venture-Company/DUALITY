#pragma once

#include "winrt/HV4DHEADER.h"
#include "winrt/HV4DDUALITY.HV4DTensors.h"
#include "winrt/HV4DDUALITY.HV4DEnvironment.h"

#include "ActivationFactory.h"

#include "ContainerUI.g.h"

namespace winrt::MassEntropy::implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI>
    {
    public:
        ContainerUI();

        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        void LoadShell();

        HV4DDUALITY::HV4DEnvironment::IHV4DCmdShell oCmdShell{ nullptr };

    private:
        void LoadInputBuffer();

        HV4DDUALITY::HV4DEnvironment::IHV4DInputBuffer oInputBuffer{ nullptr };

    private:
        void LoadPipeline();

        HV4DDUALITY::HV4DTensors::IHV4DPipeline oPipeline{ nullptr };

        void RegisterTickEvent();

        void OnTick(Windows::Foundation::IInspectable const&, Windows::Foundation::IInspectable const&);

        Microsoft::UI::Xaml::DispatcherTimer* oDispatchTimer{ nullptr };

        winrt::event_token timer_event{ 0 };

    };

}

namespace winrt::MassEntropy::factory_implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI, implementation::ContainerUI>
    {

    };

}
