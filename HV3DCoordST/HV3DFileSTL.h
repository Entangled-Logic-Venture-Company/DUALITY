#pragma once

#include "HV3DFileSTL.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DFileSTL : HV3DFileSTLT<HV3DFileSTL>
    {
        HV3DFileSTL() = default;

    };

}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DFileSTL : HV3DFileSTLT<HV3DFileSTL, implementation::HV3DFileSTL>
    {

    };

}
