#pragma once

#include "HV3DCommandLine.g.h"

namespace winrt::HV3DCmdShell::implementation
{
    struct HV3DCommandLine : HV3DCommandLineT<HV3DCommandLine>
    {
    public:
        HV3DCommandLine() = default;

        virtual void HV3DNewShell();

    private:



    };

}

namespace winrt::HV3DCmdShell::factory_implementation
{
    struct HV3DCommandLine : HV3DCommandLineT<HV3DCommandLine, implementation::HV3DCommandLine>
    {

    };

}
