#pragma once

#include "ContainerFrame.g.h"

namespace winrt::KernelsST::implementation
{
    struct ContainerFrame : ContainerFrameT<ContainerFrame>
    {
    public:
        ContainerFrame();

        void Frame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

    };
}

namespace winrt::KernelsST::factory_implementation
{
    struct ContainerFrame : ContainerFrameT<ContainerFrame, implementation::ContainerFrame>
    {
    };
}
