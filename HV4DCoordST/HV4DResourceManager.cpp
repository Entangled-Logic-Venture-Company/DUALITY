#include "pch.h"
#include "HV4DResourceManager.h"
#if __has_include("HV4DResourceManager.g.cpp")
#include "HV4DResourceManager.g.cpp"
#endif


using namespace std;

using namespace winrt;

using namespace winrt::Windows;
using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::HV4DCoordST::implementation
{
	void HV4DResourceManager::HV4DLoadInputBufferFromFile(hstring file)
	{
		oFileObj = make<HV4DFileObj>();
			
		oFileObj.LoadMeshFromFile(L"C:\\Users\\rebek\\ARCHIVE\\test.obj");



		return;

	}
	
}
