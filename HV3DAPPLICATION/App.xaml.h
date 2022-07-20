#pragma once

#include "App.xaml.g.h"

namespace winrt::HV3DAPPLICATION::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window oWindow{ nullptr };

    };

}
