#pragma once

#include "winrt/HV4DHEADER.h"
#include "winrt/HV4DDUALITY.HV4DEnvironment.h"

#include "HV4DCoreUI.g.h"

namespace winrt::DUALITY::implementation
{
    struct HV4DCoreUI : HV4DCoreUIT<HV4DCoreUI>
    {
    public:
        HV4DCoreUI();

        void Loading(winrt::Microsoft::UI::Xaml::FrameworkElement const& sender, 
            winrt::Windows::Foundation::IInspectable const& args);

        void HV4DGetCallbackInterface(HV4DDUALITY::HV4DEnvironment::IHV4DCallbackInterface e);

    private:
        HV4DDUALITY::HV4DEnvironment::IHV4DCallbackInterface oCallbackInterface;
        
    public:
        void HV4DAccessProjects001(winrt::Windows::Foundation::IInspectable const& sender,winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV4DAccessProjects002(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV4DAccessProjects003(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV4DAccessProjects004(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV4DAccessProjects005(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        winrt::hresult IndexProjects();

        winrt::hresult PopulatePortal();

        Windows::Foundation::Collections::IVector<HV4DHEADER::HV4DHeader> oHeaders{ nullptr };

    public:
        HV4DHEADER::HV4DHeader Header();
        void Header(HV4DHEADER::HV4DHeader);

    private:
        HV4DHEADER::HV4DHeader oHeader;

    private:
        /*CreateProcess*/
        void ApplicationViewFromFile();

        HANDLE                          hToken{ nullptr };
        LPCWSTR                         application_name{ nullptr };
        LPWSTR                          command_line{ nullptr };
        LPSECURITY_ATTRIBUTES           process_attributes{ nullptr };
        LPSECURITY_ATTRIBUTES           thread_attributes{ nullptr };
        BOOL                            inherit_handles{ true };
        DWORD                           creation_flags{ 0 };
        LPVOID                          environment{ nullptr };
        LPCWSTR                         current_directory{ nullptr };
        LPSTARTUPINFOW                  startup_info{ nullptr };
        LPPROCESS_INFORMATION           process_information{ nullptr };

    public:
        void isSplashVisible(float e) { state_splash_visible = e; };
        float isSplashVisible() { return state_splash_visible; }

    private:
        float state_splash_visible{ 0 };

    };

}

namespace winrt::DUALITY::factory_implementation
{
    struct HV4DCoreUI : HV4DCoreUIT<HV4DCoreUI, implementation::HV4DCoreUI>
    {
    };
}
