#pragma once

#include "HV4DHeader.g.h"

#pragma once

namespace winrt::HV4DHEADER::implementation
{

	struct HV4DHeader : HV4DHeaderT<HV4DHeader>
	{
	public:
		HV4DHeader();
		
		virtual void HV4DLoadFromFile(HV4DDUALITY::HV4DFile file);

		HV4DDUALITY::HV4DName FileXML();
		void FileXML(HV4DDUALITY::HV4DName file);

		HV4DDUALITY::HV4DDate DateModified();
		void DateModified(HV4DDUALITY::HV4DDate date);

		HV4DDUALITY::HV4DPath PathJson();
		void PathJson(HV4DDUALITY::HV4DPath path);

		HV4DDUALITY::HV4DFile FileJson();
		void FileJson(HV4DDUALITY::HV4DFile file);

		HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentCPU EnvironmentCPU();
		void EnvironmentCPU(HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentCPU ecpu);

		HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentGPU EnvironmentGPU();
		void EnvironmentGPU(HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentGPU egpu);

		HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentBindings EnvironmentBindings();
		void EnvironmentBindings(HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentBindings bind);

		HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentShell EnvironmentShell();
		void EnvironmentShell(HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentShell eshell);

		Windows::Foundation::Collections::IVector<HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentPlugin> EnvironmentPlugins();
		void EnvironmentPlugins(Windows::Foundation::Collections::IVector<HV4DDUALITY::HV4DEnvironment::HV4DEnvironmentPlugin> plugs);
		
	};

};


namespace winrt::HV4DHEADER::factory_implementation
{
	struct HV4DHeader : HV4DHeaderT<HV4DHeader, implementation::HV4DHeader>
	{
	};
}
