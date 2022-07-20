#pragma once

#include "HV3DViewmodel.g.h"

#pragma once

namespace winrt::HV3DAPPLICATION::implementation
{

	struct HV3DViewmodel : HV3DViewmodelT<HV3DViewmodel>
	{
	public:
		HV3DViewmodel();

	};

};


namespace winrt::HV3DAPPLICATION::factory_implementation
{
	struct HV3DViewmodel : HV3DViewmodelT<HV3DViewmodel, implementation::HV3DViewmodel>
	{
	};
}
