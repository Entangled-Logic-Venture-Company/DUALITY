#include "pch.h"
#include "HV3DAppFrame.xaml.h"
#if __has_include("HV3DAppFrame.g.cpp")
#include "HV3DAppFrame.g.cpp"
#endif

using namespace winrt;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;

namespace winrt::DUALITY::implementation
{
    HV3DAppFrame::HV3DAppFrame()
    {
        InitializeComponent();

    }

    void HV3DAppFrame::Frame_Navigated(IInspectable const& sender, NavigationEventArgs const& e)
    {
        oPortal = e.Content().as<HV3DDUALITY::HV3DEnvironment::IHV3DPortalInterface>();

        return;

    }

}