#include "pch.h"
#include "HV4DCoreUI.xaml.h"
#if __has_include("HV4DCoreUI.g.cpp")
#include "HV4DCoreUI.g.cpp"
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
    HV4DCoreUI::HV4DCoreUI()
    {
        InitializeComponent();

        return;

    }

    void HV4DCoreUI::Loading(winrt::Microsoft::UI::Xaml::FrameworkElement const& sender,
                                winrt::Windows::Foundation::IInspectable const& args)
    {
        winrt::check_hresult(IndexProjects());
        
        winrt::check_hresult(PopulatePortal());

        state_splash_visible = 0;

        return;

    }

    void HV4DCoreUI::HV4DGetCallbackInterface(HV4DDUALITY::HV4DEnvironment::IHV4DCallbackInterface e)
    {
        oCallbackInterface = e;

        return;

    }

    winrt::hresult HV4DCoreUI::IndexProjects()
    {


        return S_OK;

    }

    winrt::hresult HV4DCoreUI::PopulatePortal()
    {

        oHeader.FileJson().s = L"duality.cfg";

        return S_OK;

    }

    void HV4DCoreUI::HV4DAccessProjects001(IInspectable const& sender, RoutedEventArgs const& e)
    {
        ApplicationViewFromFile();

        return;

    }

    void HV4DCoreUI::HV4DAccessProjects002(IInspectable const& sender, RoutedEventArgs const& e)
    {


        return;

    }


    void HV4DCoreUI::HV4DAccessProjects003(IInspectable const& sender, RoutedEventArgs const& e)
    {

    }

    void HV4DCoreUI::HV4DAccessProjects004(IInspectable const& sender, RoutedEventArgs const& e)
    {

    }

    void HV4DCoreUI::HV4DAccessProjects005(IInspectable const& sender, RoutedEventArgs const& e)
    {

    }

    HV4DHEADER::HV4DHeader HV4DCoreUI::Header()
    {


        return oHeader;

    }

    void HV4DCoreUI::Header(HV4DHEADER::HV4DHeader e)
    {
        oHeader = e;

        return;

    }

    void HV4DCoreUI::ApplicationViewFromFile()
    {
        application_name =
            L"C:/Users/rebek/source/DUALITY/x64/Debug/HV4DApplication/HV4DApplication.exe";

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