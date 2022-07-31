#pragma once

#include "HV4DCoreFrame.xaml.h"
#include "HV4DCoreUI.xaml.h"

#include "HV4DCoreWindow.g.h"

namespace winrt::DUALITY::implementation
{
    struct HV4DCoreWindow : HV4DCoreWindowT<HV4DCoreWindow>
    {
    public:
        HV4DCoreWindow();

        void Activated(winrt::Windows::Foundation::IInspectable,
            winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs);

    private:
        HWND hWnd{ nullptr };

        Microsoft::UI::Windowing::AppWindow oAppWindow{ nullptr };

        Microsoft::UI::Xaml::Controls::Frame oAppFrame{ nullptr };

        HV4DHEADER::HV4DHeader oHeader{ nullptr };

    };

}

namespace winrt::DUALITY::factory_implementation
{
    struct HV4DCoreWindow : HV4DCoreWindowT<HV4DCoreWindow, implementation::HV4DCoreWindow>
    {

    };

}
