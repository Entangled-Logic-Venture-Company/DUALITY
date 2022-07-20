#pragma once

#include "winrt/HV3DDUALITY.HV3DEnvironment.h"

#include "HV3DAppFrame.g.h"

static winrt::HV3DDUALITY::HV3DEnvironment::IHV3DPortalInterface oPortal{ nullptr };

namespace winrt::DUALITY::implementation
{
    struct HV3DAppFrame : HV3DAppFrameT<HV3DAppFrame>
    {
        HV3DAppFrame();

        void Frame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        void Exit() { return; };

    };

}

namespace winrt::DUALITY::factory_implementation
{
    struct HV3DAppFrame : HV3DAppFrameT<HV3DAppFrame, implementation::HV3DAppFrame>
    {

    };

}
