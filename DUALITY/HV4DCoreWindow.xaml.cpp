#include "pch.h"
#include "HV4DCoreWindow.xaml.h"
#if __has_include("HV4DCoreWindow.g.cpp")
#include "HV4DCoreWindow.g.cpp"
#endif

using namespace winrt;

using namespace Windows::Foundation;

using namespace Microsoft::UI;
using namespace Microsoft::UI::Windowing;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Interop;

namespace winrt::DUALITY::implementation
{
    HV4DCoreWindow::HV4DCoreWindow()
    {
        InitializeComponent();

    }

    void HV4DCoreWindow::Activated(IInspectable sender, WindowActivatedEventArgs args)
    {
        winrt::check_hresult(this->try_as<IWindowNative>().get()->get_WindowHandle(&hWnd));

        WindowId oWindowId{};
        oWindowId = GetWindowIdFromWindow(hWnd);

        oAppWindow = AppWindow::GetFromWindowId(oWindowId);

        this->ExtendsContentIntoTitleBar(true);                  //bug fix
        oAppWindow.SetPresenter(AppWindowPresenterKind::FullScreen);
        this->ExtendsContentIntoTitleBar(false);                 //bug fix

        oAppFrame = make<HV4DCoreFrame>();
        oAppFrame.Navigate(xaml_typename<DUALITY::HV4DCoreUI>());

        this->Content(oAppFrame);

    }
    
}
