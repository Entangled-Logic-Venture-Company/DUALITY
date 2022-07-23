#include "pch.h"

#include "ContainerWindow.xaml.h"

#include "Container.xaml.h"

using namespace winrt;

using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace winrt::Microsoft::UI::Xaml::Navigation;

using namespace HV3DAPPLICATION;
using namespace HV3DAPPLICATION::implementation;

Container::Container()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

void Container::OnLaunched(LaunchActivatedEventArgs const&)
{
    oWindow = make<ContainerWindow>();
    oWindow.Activate();

}