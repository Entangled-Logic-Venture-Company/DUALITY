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
	HV3DHeader::HV3DHeader() {};
	
	HV3DName HV3DHeader::FileXML() { return {}; };
	void HV3DHeader::FileXML(HV3DName FileName) {};

	HV3DDate HV3DHeader::DateModified() { return {}; };
	void HV3DHeader::DateModified(HV3DDate Date) {};

	HV3DPath HV3DHeader::PathJson() { return {}; };
	void HV3DHeader::PathJson(HV3DPath Path) {};

	HV3DFile HV3DHeader::FileJson() { return {}; };
	void HV3DHeader::FileJson(HV3DFile File) {};

	HV3DEnvironmentCPU HV3DHeader::oEnvironmentCPU() { return {}; };
	void HV3DHeader::oEnvironmentCPU(HV3DEnvironmentCPU EnvCPU) {};

	HV3DEnvironmentGPU HV3DHeader::oEnvironmentGPU() { return {}; };
	void HV3DHeader::oEnvironmentGPU(HV3DEnvironmentGPU EnvGPU) {};

	HV3DEnvironmentBindings HV3DHeader::oEnvironmentBindings() { return {}; };
	void HV3DHeader::oEnvironmentBindings(HV3DEnvironmentBindings EnvBind) {};

	HV3DEnvironmentShell HV3DHeader::oEnvironmentShell() { return {}; };
	void HV3DHeader::oEnvironmentShell(HV3DEnvironmentShell Shell) {};

	IVector<HV3DEnvironmentPlugin> HV3DHeader::oEnvironmentPlugins() { return {}; };
	void HV3DHeader::oEnvironmentPlugins(IVector<HV3DEnvironmentPlugin> Plugins) {};
	
}
