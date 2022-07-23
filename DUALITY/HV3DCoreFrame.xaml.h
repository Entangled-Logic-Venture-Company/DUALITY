#pragma once

#include "winrt/HV3DDUALITY.HV3DEnvironment.h"

#include "HV3DCoreFrame.g.h"

static winrt::HV3DDUALITY::HV3DEnvironment::IHV3DPortalInterface oPortal{ nullptr };

namespace winrt::DUALITY::implementation
{
    struct HV3DCoreFrame : HV3DCoreFrameT<HV3DCoreFrame>
    {
        HV3DCoreFrame();

        void Frame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        void Exit() { return; };

    };

}

namespace winrt::DUALITY::factory_implementation
{
    struct HV3DCoreFrame : HV3DCoreFrameT<HV3DCoreFrame, implementation::HV3DCoreFrame>
    {

    };

}
