#pragma once

#include <winstring.h>

#include "winrt/HV4DHEADER.h"
#include "winrt/HV4DDUALITY.HV4DTensors.h"
#include "winrt/HV4DDUALITY.HV4DEnvironment.h"

#include "ContainerUI.g.h"

namespace winrt::RFiles::implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI>
    {
    public:
        ContainerUI();

        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        HV4DDUALITY::HV4DTensors::IHV4DPipeline HV4DPipeline{ nullptr };

    private:
        void RegisterTickEvent();

        void OnTick(Windows::Foundation::IInspectable const&, Windows::Foundation::IInspectable const&);

        Microsoft::UI::Xaml::DispatcherTimer* oDispatchTimer{ nullptr };

        winrt::event_token timer_event{ 0 };


    };

}

namespace winrt::RFiles::factory_implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI, implementation::ContainerUI>
    {

    };

}
