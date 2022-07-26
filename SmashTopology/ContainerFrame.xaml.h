#pragma once

#include "ContainerFrame.g.h"

namespace winrt::SmashTopology::implementation
{
    struct ContainerFrame : ContainerFrameT<ContainerFrame>
    {
    public:
        ContainerFrame();

        void Frame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

    };
}

namespace winrt::SmashTopology::factory_implementation
{
    struct ContainerFrame : ContainerFrameT<ContainerFrame, implementation::ContainerFrame>
    {
    };
}
