#pragma once

#include "Shell.g.h"

namespace winrt::HV3DComShell::implementation
{
    struct Shell : ShellT<Class>
    {
        Shell() = default;

    };

}

namespace winrt::HV3DComShell::factory_implementation
{
    struct Shell : ShellT<Shell, implementation::Shell>
    {

    };

}
