#pragma once

#include "HV4DFileSTL.g.h"

namespace winrt::HV4DCoordST::implementation
{
    struct HV4DFileSTL : HV4DFileSTLT<HV4DFileSTL>
    {
        HV4DFileSTL() = default;

    };

}

namespace winrt::HV4DCoordST::factory_implementation
{
    struct HV4DFileSTL : HV4DFileSTLT<HV4DFileSTL, implementation::HV4DFileSTL>
    {

    };

}
