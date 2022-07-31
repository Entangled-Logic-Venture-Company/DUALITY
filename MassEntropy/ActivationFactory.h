#pragma once

#include <winstring.h>

namespace HV4DHelpers {

	winrt::Windows::Foundation::IActivationFactory GetActivationFactory(std::wstring dll, std::wstring coclass);

}
