#include "pch.h"
#include "ContainerFrame.xaml.h"
#if __has_include("ContainerFrame.g.cpp")
#include "ContainerFrame.g.cpp"
#endif

using namespace winrt;

using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace winrt::Microsoft::UI::Xaml::Navigation;

namespace winrt::PhotonicEVM::implementation
{
    ContainerFrame::ContainerFrame()
    {
        InitializeComponent();

        return;

    }

    void ContainerFrame::Frame_Navigated(Windows::Foundation::IInspectable const& sender, 
        NavigationEventArgs const& e)
    {

        return;

    }

}