#pragma once

#include "HV4DFileObj.h"

#include "HV4DResourceManager.g.h"

namespace winrt::HV4DCoordST::implementation
{
    struct HV4DResourceManager : HV4DResourceManagerT<HV4DResourceManager>
    {
    public:
        HV4DResourceManager() = default;

        virtual void HV4DLoadInputBufferFromFile(winrt::hstring file);

    private:
        winrt::HV4DCoordST::HV4DFileObj oFileObj{ nullptr };


    };

}

namespace winrt::HV4DCoordST::factory_implementation
{
    struct HV4DResourceManager : HV4DResourceManagerT<HV4DResourceManager, implementation::HV4DResourceManager>
    {

    };

}
