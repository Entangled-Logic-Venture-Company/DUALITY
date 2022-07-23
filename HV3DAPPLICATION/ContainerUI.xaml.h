#pragma once

#include <winstring.h>

#include "winrt/HV3DHEADER.h"
#include "winrt/HV3DDUALITY.HV3DEnvironment.h"

#include "ContainerUI.g.h"

namespace winrt::HV3DAPPLICATION::implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI>
    {
    public:
        ContainerUI();

        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        winrt::com_ptr<HV3DDUALITY::HV3DView::IHV3DPipeline> oPipeline;

    };

}

namespace winrt::HV3DAPPLICATION::factory_implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI, implementation::ContainerUI>
    {

    };

}
