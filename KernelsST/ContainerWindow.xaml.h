#pragma once

#include "ContainerFrame.xaml.h"
#include "ContainerUI.xaml.h"

#include "ContainerWindow.g.h"

namespace winrt::KernelsST::implementation
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

        winrt::KernelsST::ContainerFrame      oApplicationFrame{ nullptr };

        HV4DHEADER::HV4DHeader                      oApplicationHeader{ nullptr };

    };

}

namespace winrt::KernelsST::factory_implementation
{
    struct ContainerWindow : ContainerWindowT<ContainerWindow, implementation::ContainerWindow>
    {
    };
}
