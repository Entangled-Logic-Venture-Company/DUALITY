#include "pch.h"
#include "HV4DCoreFrame.xaml.h"
#if __has_include("HV4DCoreFrame.g.cpp")
#include "HV4DCoreFrame.g.cpp"
#endif

using namespace winrt;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;

namespace winrt::DUALITY::implementation
{
    HV4DCoreFrame::HV4DCoreFrame()
    {
        InitializeComponent();

    }

    void HV4DCoreFrame::Frame_Navigated(IInspectable const& sender, NavigationEventArgs const& e)
    {
        oPortal = e.Content().as<HV4DDUALITY::HV4DEnvironment::IHV4DPortalInterface>();

        return;

    }

}