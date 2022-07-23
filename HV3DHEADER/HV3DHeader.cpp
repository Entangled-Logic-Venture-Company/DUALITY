#include "pch.h"
#include "HV3DHeader.h"
#if __has_include("HV3DHeader.g.cpp")
#include "HV3DHeader.g.cpp"
#endif

using namespace winrt;

using namespace Windows::Foundation::Collections;

using namespace HV3DDUALITY;
using namespace HV3DDUALITY::HV3DEnvironment;

namespace winrt::HV3DHEADER::implementation
{
	HV3DHeader::HV3DHeader() 
	{
	
	
		return;
	
	};

	void HV3DHeader::HV3DLoadFromFile(HV3DDUALITY::HV3DFile file)
	{ 
		
		
		return; 
	
	};
	
	HV3DName HV3DHeader::FileXML() { return {}; };
	void HV3DHeader::FileXML(HV3DName file) {};

	HV3DDate HV3DHeader::DateModified() { return {}; };
	void HV3DHeader::DateModified(HV3DDate date) {};

	HV3DPath HV3DHeader::PathJson() { return {}; };
	void HV3DHeader::PathJson(HV3DPath path) {};

	HV3DFile HV3DHeader::FileJson() { return {}; };
	void HV3DHeader::FileJson(HV3DFile file) {};

	HV3DEnvironmentCPU HV3DHeader::EnvironmentCPU() { return {}; };
	void HV3DHeader::EnvironmentCPU(HV3DEnvironmentCPU ecpu) {};

	HV3DEnvironmentGPU HV3DHeader::EnvironmentGPU() { return {}; };
	void HV3DHeader::EnvironmentGPU(HV3DEnvironmentGPU egpu) {};

	HV3DEnvironmentBindings HV3DHeader::EnvironmentBindings() { return {}; };
	void HV3DHeader::EnvironmentBindings(HV3DEnvironmentBindings bind) {};

	HV3DEnvironmentShell HV3DHeader::EnvironmentShell() { return {}; };
	void HV3DHeader::EnvironmentShell(HV3DEnvironmentShell shell) {};

	IVector<HV3DEnvironmentPlugin> HV3DHeader::EnvironmentPlugins() { return {}; };
	void HV3DHeader::EnvironmentPlugins(IVector<HV3DEnvironmentPlugin> plugs) {};
	
}
