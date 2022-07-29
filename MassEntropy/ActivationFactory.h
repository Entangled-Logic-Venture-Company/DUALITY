#pragma once

#include <winstring.h>

namespace HV3DHelpers {

	winrt::Windows::Foundation::IActivationFactory GetActivationFactory(std::wstring dll, std::wstring coclass);

}
