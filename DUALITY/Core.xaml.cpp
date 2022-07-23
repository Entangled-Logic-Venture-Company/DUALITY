#include "pch.h"

#include "Core.xaml.h"

using namespace winrt;

using namespace Windows::Foundation;

using namespace Microsoft::UI::Xaml;

namespace winrt::DUALITY::implementation {

    Core::Core()
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

    void Core::OnLaunched(LaunchActivatedEventArgs const&)
    {
        oCoreWindow = make<HV3DCoreWindow>();
        oCoreWindow.Activate();

    }

}