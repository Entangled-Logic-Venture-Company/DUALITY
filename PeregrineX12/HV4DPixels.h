#pragma once

#include "HV4DShader.h"

namespace PeregrineX12
{
    class HV4DPixels
    {
    public:
        HV4DPixels() = default;

        HV4DShader HV4DLoadShaderResource(std::wstring);

    };

}