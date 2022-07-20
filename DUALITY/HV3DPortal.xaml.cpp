#include "pch.h"
#include "HV3DPortal.xaml.h"
#if __has_include("HV3DPortal.g.cpp")
#include "HV3DPortal.g.cpp"
#endif

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml::Interop;

using namespace winrt;

using namespace Microsoft::UI::Windowing;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Interop;
using namespace Microsoft::UI::Xaml::Media;

namespace winrt::DUALITY::implementation
{
    HV3DPortal::HV3DPortal()
    {
        InitializeComponent();

        return;

    }

    void HV3DPortal::Loading(winrt::Microsoft::UI::Xaml::FrameworkElement const& sender,
                                winrt::Windows::Foundation::IInspectable const& args)
    {
        winrt::check_hresult(IndexProjects());
        
        winrt::check_hresult(PopulatePortal());

        state_splash_visible = 0;

        return;

    }

    void HV3DPortal::GetCallbackInterface(HV3DDUALITY::HV3DEnvironment::IHV3DCallbackInterface e)
    {
        oCallbackInterface = e;

        return;

    }

    winrt::hresult HV3DPortal::IndexProjects()
    {


        return S_OK;

    }

    winrt::hresult HV3DPortal::PopulatePortal()
    {

        oHeader.FileJson().File = L"duality.cfg";

        return S_OK;

    }

    void HV3DPortal::HV3DAccessProjects001(IInspectable const& sender, RoutedEventArgs const& e)
    {
        ApplicationViewFromFile();

        return;

    }

    void HV3DPortal::HV3DAccessProjects002(IInspectable const& sender, RoutedEventArgs const& e)
    {


        return;

    }


    void HV3DPortal::HV3DAccessProjects003(IInspectable const& sender, RoutedEventArgs const& e)
    {

    }

    void HV3DPortal::HV3DAccessProjects004(IInspectable const& sender, RoutedEventArgs const& e)
    {

    }

    void HV3DPortal::HV3DAccessProjects005(IInspectable const& sender, RoutedEventArgs const& e)
    {

    }

    HV3DHEADER::HV3DHeader HV3DPortal::Header()
    {


        return oHeader;

    }

    void HV3DPortal::Header(HV3DHEADER::HV3DHeader e)
    {
        oHeader = e;

        return;

    }

    void HV3DPortal::ApplicationViewFromFile()
    {
        application_name =
            L"C:/Users/rebek/source/DUALITY/x64/Debug/HV3DApplication/HV3DApplication.exe";

        creation_flags = NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW | CREATE_NEW_PROCESS_GROUP;

        current_directory =
            L"C:/Users/rebek/source/DUALITY/x64/Debug/DUALITY/";

        startup_info = new STARTUPINFOW{
            sizeof(STARTUPINFOW),
            nullptr, nullptr, L"DUALITY",
            0, 0, 0, 0, 0, 0, 0, 0,
            SW_SHOWDEFAULT,
            0, nullptr, nullptr, nullptr, nullptr };

        process_information = new PROCESS_INFORMATION{
            nullptr, nullptr, 0, 0 };

        BOOL ret = CreateProcessAsUserW(
            hToken,
            application_name,
            command_line,
            process_attributes,
            thread_attributes,
            inherit_handles,
            creation_flags,
            environment,
            current_directory,
            startup_info,
            process_information);

        return;

    }

}