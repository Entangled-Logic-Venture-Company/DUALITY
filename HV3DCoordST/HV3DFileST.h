#pragma once

#include "HV3DFileST.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DFileST : HV3DFileSTT<HV3DFileST>
    {
        HV3DFileST() = default;

    };

}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DFileST : HV3DFileSTT<HV3DFileST, implementation::HV3DFileST>
    {

    };

}
