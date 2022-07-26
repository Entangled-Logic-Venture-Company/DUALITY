#pragma once

#include <winstring.h>

#include "winrt/HV3DHEADER.h"
#include "winrt/HV3DDUALITY.HV3DView.h"
#include "winrt/HV3DDUALITY.HV3DEnvironment.h"

#include "ContainerUI.g.h"

namespace winrt::RFiles::implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI>
    {
    public:
        ContainerUI();

        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        HV3DDUALITY::HV3DView::IHV3DPipeline HV3DPipeline{ nullptr };

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
