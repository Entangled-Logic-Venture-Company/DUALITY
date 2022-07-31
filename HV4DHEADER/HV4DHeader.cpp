#include "pch.h"
#include "HV4DHeader.h"
#if __has_include("HV4DHeader.g.cpp")
#include "HV4DHeader.g.cpp"
#endif

using namespace winrt;

using namespace Windows::Foundation::Collections;

using namespace HV4DDUALITY;
using namespace HV4DDUALITY::HV4DEnvironment;

namespace winrt::HV4DHEADER::implementation
{
	HV4DHeader::HV4DHeader() 
	{
	
	
		return;
	
	};

	void HV4DHeader::HV4DLoadFromFile(HV4DDUALITY::HV4DFile file)
	{ 
		
		
		return; 
	
	};
	
	HV4DName HV4DHeader::FileXML() { return {}; };
	void HV4DHeader::FileXML(HV4DName file) {};

	HV4DDate HV4DHeader::DateModified() { return {}; };
	void HV4DHeader::DateModified(HV4DDate date) {};

	HV4DPath HV4DHeader::PathJson() { return {}; };
	void HV4DHeader::PathJson(HV4DPath path) {};

	HV4DFile HV4DHeader::FileJson() { return {}; };
	void HV4DHeader::FileJson(HV4DFile file) {};

	HV4DEnvironmentCPU HV4DHeader::EnvironmentCPU() { return {}; };
	void HV4DHeader::EnvironmentCPU(HV4DEnvironmentCPU ecpu) {};

	HV4DEnvironmentGPU HV4DHeader::EnvironmentGPU() { return {}; };
	void HV4DHeader::EnvironmentGPU(HV4DEnvironmentGPU egpu) {};

	HV4DEnvironmentBindings HV4DHeader::EnvironmentBindings() { return {}; };
	void HV4DHeader::EnvironmentBindings(HV4DEnvironmentBindings bind) {};

	HV4DEnvironmentShell HV4DHeader::EnvironmentShell() { return {}; };
	void HV4DHeader::EnvironmentShell(HV4DEnvironmentShell shell) {};

	IVector<HV4DEnvironmentPlugin> HV4DHeader::EnvironmentPlugins() { return {}; };
	void HV4DHeader::EnvironmentPlugins(IVector<HV4DEnvironmentPlugin> plugs) {};
	
}
