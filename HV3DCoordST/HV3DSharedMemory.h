#pragma once

#include "HV3DSharedMemory.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DSharedMemory : HV3DSharedMemoryT<HV3DSharedMemory>
    {
        HV3DSharedMemory() = default;

    };

}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DSharedMemory : HV3DSharedMemoryT<HV3DSharedMemory, implementation::HV3DSharedMemory>
    {

    };

}
