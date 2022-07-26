#pragma once

#include "Container.xaml.h"

#include "Container.xaml.g.h"

namespace winrt::PhotonicEVM::implementation
{
    struct Container : AppT<Container>
    {
        Container();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window oWindow{ nullptr };

    };

}
