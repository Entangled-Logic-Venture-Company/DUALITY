#pragma once

#include "HV4DFileFBX.g.h"

namespace winrt::HV4DCoordST::implementation
{
    struct HV4DFileFBX : HV4DFileFBXT<HV4DFileFBX>
    {
        HV4DFileFBX() = default;

    };
}

namespace winrt::HV4DCoordST::factory_implementation
{
    struct HV4DFileFBX : HV4DFileFBXT<HV4DFileFBX, implementation::HV4DFileFBX>
    {
    };
}
