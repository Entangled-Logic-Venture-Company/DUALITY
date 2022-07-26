#pragma once

#include "ContainerFrame.g.h"

namespace winrt::MetaPhysical::implementation
{
    struct ContainerFrame : ContainerFrameT<ContainerFrame>
    {
    public:
        ContainerFrame();

        void Frame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

    };
}

namespace winrt::MetaPhysical::factory_implementation
{
    struct ContainerFrame : ContainerFrameT<ContainerFrame, implementation::ContainerFrame>
    {
    };
}
