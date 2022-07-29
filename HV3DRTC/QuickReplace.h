#pragma once

#include "QuickReplace.g.h"

namespace winrt::Namespace::implementation
{
    struct QuickReplace : QuickReplaceT<QuickReplace>
    {
        QuickReplace() = default;

    };

}

namespace winrt::Namespace::factory_implementation
{
    struct QuickReplace : QuickReplaceT<QuickReplace, implementation::QuickReplace>
    {

    };

}
