#pragma once

#include "HV4DSharedMemory.g.h"

namespace winrt::HV4DCoordST::implementation
{
    struct HV4DSharedMemory : HV4DSharedMemoryT<HV4DSharedMemory>
    {
        HV4DSharedMemory() = default;

    };

}

namespace winrt::HV4DCoordST::factory_implementation
{
    struct HV4DSharedMemory : HV4DSharedMemoryT<HV4DSharedMemory, implementation::HV4DSharedMemory>
    {

    };

}
