#pragma once

#include "winrt/HV3DHEADER.h"
#include "winrt/HV3DDUALITY.HV3DView.h"
#include "winrt/HV3DDUALITY.HV3DEnvironment.h"

#include "ActivationFactory.h"

#include "ContainerUI.g.h"

namespace winrt::MassEntropy::implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI>
    {
    public:
        ContainerUI();

        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        void LoadShell();

        HV3DDUALITY::HV3DEnvironment::IHV3DCmdShell oCmdShell{ nullptr };

    private:
        void LoadInputBuffer();

        HV3DDUALITY::HV3DEnvironment::IHV3DInputBuffer oInputBuffer{ nullptr };

    private:
        void LoadPipeline();

        HV3DDUALITY::HV3DView::IHV3DPipeline oPipeline{ nullptr };

        void RegisterTickEvent();

        void OnTick(Windows::Foundation::IInspectable const&, Windows::Foundation::IInspectable const&);

        Microsoft::UI::Xaml::DispatcherTimer* oDispatchTimer{ nullptr };

        winrt::event_token timer_event{ 0 };

    };

}

namespace winrt::MassEntropy::factory_implementation
{
    struct ContainerUI : ContainerUIT<ContainerUI, implementation::ContainerUI>
    {

    };

}
