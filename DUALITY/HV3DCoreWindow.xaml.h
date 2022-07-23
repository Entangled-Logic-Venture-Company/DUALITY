#pragma once

#include "HV3DCoreFrame.xaml.h"
#include "HV3DCoreUI.xaml.h"

#include "HV3DCoreWindow.g.h"

namespace winrt::DUALITY::implementation
{
    struct HV3DCoreWindow : HV3DCoreWindowT<HV3DCoreWindow>
    {
    public:
        HV3DCoreWindow();

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
    struct HV3DCoreWindow : HV3DCoreWindowT<HV3DCoreWindow, implementation::HV3DCoreWindow>
    {

    };

}
