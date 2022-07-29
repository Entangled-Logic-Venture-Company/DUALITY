#include "pch.h"

#include "ActivationFactory.h"

using namespace std;

using namespace winrt;

using namespace winrt::Windows;
using namespace winrt::Windows::Foundation;

using namespace winrt::Microsoft::UI::Xaml;

namespace HV3DHelpers {

    winrt::Windows::Foundation::IActivationFactory GetActivationFactory(std::wstring dll, std::wstring coclass)
    {
        int32_t ret = 0;

        void* dllHandle = WINRT_IMPL_LoadLibraryW(dll.c_str());

        if (!dllHandle) { throw; };

        void* proc = WINRT_IMPL_GetProcAddress(dllHandle, "DllGetActivationFactory");
        auto DllGetActivationFactory = reinterpret_cast<int32_t(__stdcall*)(void* classId, void** factory)>(proc);

        const wchar_t* cname{ coclass.c_str() };
        const UINT32 cnamelen = (UINT32)wcslen(cname);

        HSTRING hcname = NULL;
        HSTRING_HEADER header;
        HRESULT hr = WindowsCreateStringReference(cname, cnamelen, &header, &hcname);

        void** unkActivationFactory = new void* [1];
        ret = (*DllGetActivationFactory)(&header, unkActivationFactory);

        winrt::Windows::Foundation::IActivationFactory oObj{ nullptr };
        winrt::copy_from_abi(oObj, *unkActivationFactory);

        WindowsDeleteString(hcname);

        return oObj;

    };

}