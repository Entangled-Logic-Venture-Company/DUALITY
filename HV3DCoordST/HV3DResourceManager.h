#pragma once

#include "HV3DFileObj.h"

#include "HV3DResourceManager.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DResourceManager : HV3DResourceManagerT<HV3DResourceManager>
    {
    public:
        HV3DResourceManager() = default;

        virtual void HV3DLoadInputBufferFromFile(winrt::hstring file);

    private:
        winrt::HV3DCoordST::HV3DFileObj oFileObj{ nullptr };


    };

}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DResourceManager : HV3DResourceManagerT<HV3DResourceManager, implementation::HV3DResourceManager>
    {

    };

}
