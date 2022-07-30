#include "pch.h"
#include "HV3DResourceManager.h"
#if __has_include("HV3DResourceManager.g.cpp")
#include "HV3DResourceManager.g.cpp"
#endif


using namespace std;

using namespace winrt;

using namespace winrt::Windows;
using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::HV3DCoordST::implementation
{
	void HV3DResourceManager::HV3DLoadInputBufferFromFile(hstring file)
	{
		oFileObj = make<HV3DFileObj>();
			
		oFileObj.LoadMeshFromFile(L"C:\\Users\\rebek\\ARCHIVE\\test.obj");



		return;

	}
	
}
