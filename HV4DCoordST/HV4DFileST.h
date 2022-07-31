#pragma once

#include "HV4DFileST.g.h"

namespace winrt::HV4DCoordST::implementation
{
    struct HV4DFileST : HV4DFileSTT<HV4DFileST>
    {
        HV4DFileST() = default;

    };

}

namespace winrt::HV4DCoordST::factory_implementation
{
    struct HV4DFileST : HV4DFileSTT<HV4DFileST, implementation::HV4DFileST>
    {

    };

}
