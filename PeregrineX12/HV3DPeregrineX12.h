#pragma once

#include "HV3DPeregrineX12.g.h"

namespace winrt::PeregrineX12::implementation
{
    struct HV3DPeregrineX12 : HV3DPeregrineX12T<HV3DPeregrineX12>
    {
    public:
        HV3DPeregrineX12() = default;

        void LoadPipeline() {};

    };

}

namespace winrt::PeregrineX12::factory_implementation
{
    struct HV3DPeregrineX12 : HV3DPeregrineX12T<HV3DPeregrineX12, implementation::HV3DPeregrineX12>
    {

    };

}
