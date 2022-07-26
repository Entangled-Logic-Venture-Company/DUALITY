﻿#pragma once

#include "Class.g.h"

namespace winrt::HV3DCoordSpace::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::HV3DCoordSpace::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
