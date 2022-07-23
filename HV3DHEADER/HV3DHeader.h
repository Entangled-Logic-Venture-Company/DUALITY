#pragma once

#include "HV3DHeader.g.h"

#pragma once

namespace winrt::HV3DHEADER::implementation
{

	struct HV3DHeader : HV3DHeaderT<HV3DHeader>
	{
	public:
		HV3DHeader();
		
		virtual void HV3DLoadFromFile(HV3DDUALITY::HV3DFile file);

		HV3DDUALITY::HV3DName FileXML();
		void FileXML(HV3DDUALITY::HV3DName file);

		HV3DDUALITY::HV3DDate DateModified();
		void DateModified(HV3DDUALITY::HV3DDate date);

		HV3DDUALITY::HV3DPath PathJson();
		void PathJson(HV3DDUALITY::HV3DPath path);

		HV3DDUALITY::HV3DFile FileJson();
		void FileJson(HV3DDUALITY::HV3DFile file);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentCPU EnvironmentCPU();
		void EnvironmentCPU(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentCPU ecpu);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentGPU EnvironmentGPU();
		void EnvironmentGPU(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentGPU egpu);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentBindings EnvironmentBindings();
		void EnvironmentBindings(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentBindings bind);

		HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentShell EnvironmentShell();
		void EnvironmentShell(HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentShell eshell);

		Windows::Foundation::Collections::IVector<HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentPlugin> EnvironmentPlugins();
		void EnvironmentPlugins(Windows::Foundation::Collections::IVector<HV3DDUALITY::HV3DEnvironment::HV3DEnvironmentPlugin> plugs);
		
	};

};


namespace winrt::HV3DHEADER::factory_implementation
{
	struct HV3DHeader : HV3DHeaderT<HV3DHeader, implementation::HV3DHeader>
	{
	};
}
