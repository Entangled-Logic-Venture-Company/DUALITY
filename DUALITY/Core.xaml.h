#pragma once

#include <winstring.h>
#include <activation.h>

#include "HV4DCoreWindow.xaml.h"

#include "Core.xaml.g.h"

namespace winrt::DUALITY::implementation
{
    struct Core : AppT<Core>
    {
    public:
        Core();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::DUALITY::HV4DCoreWindow oCoreWindow{ nullptr };

    };

}
