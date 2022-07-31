#pragma once

#include "winrt/HV4DDUALITY.HV4DEnvironment.h"

#include "HV4DCoreFrame.g.h"

static winrt::HV4DDUALITY::HV4DEnvironment::IHV4DPortalInterface oPortal{ nullptr };

namespace winrt::DUALITY::implementation
{
    struct HV4DCoreFrame : HV4DCoreFrameT<HV4DCoreFrame>
    {
        HV4DCoreFrame();

        void Frame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        void Exit() { return; };

    };

}

namespace winrt::DUALITY::factory_implementation
{
    struct HV4DCoreFrame : HV4DCoreFrameT<HV4DCoreFrame, implementation::HV4DCoreFrame>
    {

    };

}
