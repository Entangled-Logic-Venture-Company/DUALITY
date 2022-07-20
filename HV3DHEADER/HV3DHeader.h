#pragma once

#include "HV3DHeader.g.h"

#pragma once

namespace winrt::HV3DHEADER::implementation
{

	struct HV3DHeader : HV3DHeaderT<HV3DHeader>
	{
	public:
		HV3DHeader();
		
		void LoadFromFile(HV3DDUALITY::HV3DFile file) { return; };

		HV3DDUALITY::HV3DName FileXML();
		void FileXML(HV3DDUALITY::HV3DName FileName);

		HV3DDUALITY::HV3DDate DateModified();
		void DateModified(HV3DDUALITY::HV3DDate Date);

		HV3DDUALITY::HV3DPath PathJson();
		void PathJson(HV3DDUALITY::HV3DPath Path);

		HV3DDUALITY::HV3DFile FileJson();
		void FileJson(HV3DDUALITY::HV3DFile File);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentCPU oEnvironmentCPU();
		void oEnvironmentCPU(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentCPU EnvCPU);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentGPU oEnvironmentGPU();
		void oEnvironmentGPU(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentGPU EnvGPU);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentBindings oEnvironmentBindings();
		void oEnvironmentBindings(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentBindings EnvBind);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentShell oEnvironmentShell();
		void oEnvironmentShell(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentShell Shell);

		Windows::Foundation::Collections::IVector<HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentPlugin> oEnvironmentPlugins();
		void oEnvironmentPlugins(Windows::Foundation::Collections::IVector<HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentPlugin> Plugins);
		
	};

};


namespace winrt::HV3DHEADER::factory_implementation
{
	struct HV3DHeader : HV3DHeaderT<HV3DHeader, implementation::HV3DHeader>
	{
	};
}
