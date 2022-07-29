#pragma once

#include "HV3DFileFBX.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DFileFBX : HV3DFileFBXT<HV3DFileFBX>
    {
        HV3DFileFBX() = default;

    };
}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DFileFBX : HV3DFileFBXT<HV3DFileFBX, implementation::HV3DFileFBX>
    {
    };
}
