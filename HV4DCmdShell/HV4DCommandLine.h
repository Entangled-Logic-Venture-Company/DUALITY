#pragma once

#include "HV4DCommandLine.g.h"

namespace winrt::HV4DCmdShell::implementation
{
    struct HV4DCommandLine : HV4DCommandLineT<HV4DCommandLine>
    {
    public:
        HV4DCommandLine() = default;

        virtual void HV4DNewShell();

    private:



    };

}

namespace winrt::HV4DCmdShell::factory_implementation
{
    struct HV4DCommandLine : HV4DCommandLineT<HV4DCommandLine, implementation::HV4DCommandLine>
    {

    };

}
