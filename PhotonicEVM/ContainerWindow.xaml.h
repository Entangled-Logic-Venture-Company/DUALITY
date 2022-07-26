#pragma once

#include "ContainerFrame.xaml.h"
#include "ContainerUI.xaml.h"

#include "ContainerWindow.g.h"

namespace winrt::PhotonicEVM::implementation
{
    struct ContainerWindow : ContainerWindowT<ContainerWindow>
    {
        ContainerWindow();

        void Window_Activated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args);

    private:
        HWND                                        hWnd{ nullptr };

        winrt::com_ptr<IWindowNative>               nativeWindow{ nullptr };

        Microsoft::UI::Windowing::AppWindow         oApplicationWindow{ nullptr };

        winrt::PhotonicEVM::ContainerFrame      oApplicationFrame{ nullptr };

        HV3DHEADER::HV3DHeader                      oApplicationHeader{ nullptr };

    };

}

namespace winrt::PhotonicEVM::factory_implementation
{
    struct ContainerWindow : ContainerWindowT<ContainerWindow, implementation::ContainerWindow>
    {
    };
}
