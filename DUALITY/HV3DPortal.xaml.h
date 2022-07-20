#pragma once

#include "winrt/HV3DHEADER.h"
#include "winrt/HV3DDUALITY.HV3DEnvironment.h"

#include "HV3DPortal.g.h"

namespace winrt::DUALITY::implementation
{
    struct HV3DPortal : HV3DPortalT<HV3DPortal>
    {
    public:
        HV3DPortal();

        void Loading(winrt::Microsoft::UI::Xaml::FrameworkElement const& sender, 
            winrt::Windows::Foundation::IInspectable const& args);

        void GetCallbackInterface(HV3DDUALITY::HV3DEnvironment::IHV3DCallbackInterface e);

    private:
        HV3DDUALITY::HV3DEnvironment::IHV3DCallbackInterface oCallbackInterface;
        
    public:
        void HV3DAccessProjects001(winrt::Windows::Foundation::IInspectable const& sender,winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV3DAccessProjects002(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV3DAccessProjects003(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV3DAccessProjects004(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void HV3DAccessProjects005(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        winrt::hresult IndexProjects();

        winrt::hresult PopulatePortal();

        Windows::Foundation::Collections::IVector<HV3DHEADER::HV3DHeader> oHeaders{ nullptr };

    public:
        HV3DHEADER::HV3DHeader Header();
        void Header(HV3DHEADER::HV3DHeader);

    private:
        HV3DHEADER::HV3DHeader oHeader;

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
    struct HV3DPortal : HV3DPortalT<HV3DPortal, implementation::HV3DPortal>
    {
    };
}
