#include "pch.h"
#include "HV3DCoreFrame.xaml.h"
#if __has_include("HV3DCoreFrame.g.cpp")
#include "HV3DCoreFrame.g.cpp"
#endif

using namespace winrt;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;

namespace winrt::DUALITY::implementation
{
    HV3DCoreFrame::HV3DCoreFrame()
    {
        InitializeComponent();

    }

    void HV3DCoreFrame::Frame_Navigated(IInspectable const& sender, NavigationEventArgs const& e)
    {
        oPortal = e.Content().as<HV3DDUALITY::HV3DEnvironment::IHV3DPortalInterface>();

        return;

    }

}