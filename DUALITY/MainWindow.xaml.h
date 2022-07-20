#pragma once

#include "HV3DAppFrame.xaml.h"
#include "HV3DPortal.xaml.h"

#include "MainWindow.g.h"

namespace winrt::DUALITY::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
    public:
        MainWindow();

        void Activated(winrt::Windows::Foundation::IInspectable,
            winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs);

    private:
        HWND hWnd{ nullptr };

        Microsoft::UI::Windowing::AppWindow oAppWindow{ nullptr };

        Microsoft::UI::Xaml::Controls::Frame oAppFrame{ nullptr };

        HV3DHEADER::HV3DHeader oHeader{ nullptr };

    };

}

namespace winrt::DUALITY::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {

    };

}
