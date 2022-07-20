#pragma once

#include <winstring.h>
#include <activation.h>

#include "MainWindow.xaml.h"

#include "App.xaml.g.h"

static winrt::DUALITY::MainWindow oAppWindow{ nullptr };

namespace winrt::DUALITY::implementation
{
    struct App : AppT<App>
    {
    public:
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    };

}
