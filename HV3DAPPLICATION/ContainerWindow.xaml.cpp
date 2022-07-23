#include "pch.h"
#include "ContainerWindow.xaml.h"
#if __has_include("ContainerWindow.g.cpp")
#include "ContainerWindow.g.cpp"
#endif

using namespace winrt;

using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI;
using namespace winrt::Microsoft::UI::Windowing;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace winrt::Microsoft::UI::Xaml::Interop;

namespace winrt::HV3DAPPLICATION::implementation
{
    ContainerWindow::ContainerWindow()
    {
        InitializeComponent();

        return;

    }

    void ContainerWindow::Window_Activated(Windows::Foundation::IInspectable const& sender, WindowActivatedEventArgs const& args)
    {
        HRESULT hr = S_OK;

        nativeWindow = this->try_as<IWindowNative>();

        hr = nativeWindow.get()->get_WindowHandle(&hWnd);

        WindowId oWindowId{};
        oWindowId = GetWindowIdFromWindow(hWnd);

        oApplicationWindow = AppWindow::GetFromWindowId(oWindowId);
        oApplicationWindow.Title(L"HV3DAPPLICATION");

        this->ExtendsContentIntoTitleBar(true);                  //bug fix
        oApplicationWindow.SetPresenter(AppWindowPresenterKind::FullScreen);
        this->ExtendsContentIntoTitleBar(false);                 //bug fix

        oApplicationFrame = make<ContainerFrame>();
        oApplicationFrame.Navigate(winrt::xaml_typename<HV3DAPPLICATION::ContainerUI>());

        this->Content(oApplicationFrame);

        return;

    }

}
