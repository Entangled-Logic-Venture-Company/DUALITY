#include "pch.h"

#include "Container.xaml.h"

#include "ContainerWindow.xaml.h"

using namespace winrt;

using namespace winrt::Windows::Foundation;

using namespace winrt::Windows::ApplicationModel::Activation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::Storage;

using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace winrt::Microsoft::UI::Xaml::Navigation;

using namespace MassEntropy;
using namespace MassEntropy::implementation;

using namespace winrt::Microsoft::Windows::AppLifecycle;
using namespace winrt::Microsoft::Windows;


int activation_count = 1;

event_token activation_token;

winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> oMessages;

wil::unique_event redirect_event_handle;

winrt::hstring KindString(winrt::Windows::ApplicationModel::Activation::ActivationKind kind)
{
    switch (kind)
    {
    case ActivationKind::Launch: return winrt::hstring(L"Launch");
    
    case ActivationKind::File: return winrt::hstring(L"File");
    
    default: return winrt::hstring(L"Unknown");
            
    }

}

winrt::hstring KindString(winrt::Microsoft::Windows::AppLifecycle::ExtendedActivationKind extendedKind)
{
    switch (extendedKind)
    {
    case ExtendedActivationKind::Launch: return winrt::hstring(L"Launch");

    case ExtendedActivationKind::File: return winrt::hstring(L"File");

    default: return winrt::hstring(L"Unknown");

    }

}

void OutputMessage(const WCHAR* message)
{
    oMessages.Append(PropertyValue::CreateString(message));

    return;

}

void OutputFormattedMessage(const WCHAR* fmt, ...)
{
    WCHAR message[1025];

    va_list args;

    va_start(args, fmt);

    wvsprintf(message, fmt, args);

    va_end(args);

    OutputMessage(message);

}

std::vector<std::wstring> SplitStrings(hstring argString)
{
    std::vector<std::wstring> argStrings;

    std::wistringstream iss(argString.c_str());

    for (std::wstring s; iss >> s; )
    {
        argStrings.push_back(s);
    
    }
    
    return argStrings;

}

void GetActivationInfo()
{
    AppActivationArguments args = AppInstance::GetCurrent().GetActivatedEventArgs();

    ExtendedActivationKind kind = args.Kind();

    if (kind == ExtendedActivationKind::Launch)
    {
        auto launchArgs = args.Data().as<winrt::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>();
        
        if (launchArgs)
        {
            auto argString = launchArgs.Arguments();
        
            std::vector<std::wstring> argStrings = SplitStrings(argString);
            
            OutputMessage(L"Launch activation");
            
            for (std::wstring const& s : argStrings)
            {
                OutputMessage(s.c_str());
            
            }
        
        }
    
    }  
    else if (kind == ExtendedActivationKind::File)
    {
        IFileActivatedEventArgs fileArgs = args.Data().as<IFileActivatedEventArgs>();
     
        if (fileArgs)
        {
            IStorageItem file{ fileArgs.Files().GetAt(0) };
        
            OutputFormattedMessage(L"File activation for '%s'", file.Name().c_str());

        }

    }

}

void ReportLaunchArgs(hstring callLocation, AppActivationArguments args)
{
    winrt::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs launchArgs =
        args.Data().as<winrt::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>();

    if (launchArgs)
    {
        winrt::hstring argString = launchArgs.Arguments();
    
        std::vector<std::wstring> argStrings = SplitStrings(argString);
        
        OutputFormattedMessage(L"Launch activation (%s)", callLocation.c_str());
        
        for (std::wstring const& s : argStrings)
        {
            OutputMessage(s.c_str());
        
        }
    
    }

}

void ReportFileArgs(hstring callLocation, AppActivationArguments args)
{
    IFileActivatedEventArgs fileArgs = args.Data().as<IFileActivatedEventArgs>();

    if (fileArgs)
    {
        IStorageItem file{ fileArgs.Files().GetAt(0) };

        OutputFormattedMessage(
            L"File activation (%s) for '%s'", callLocation.c_str(), file.Name().c_str());

    }

}

winrt::fire_and_forget Redirect(AppInstance keyInstance, AppActivationArguments args)
{
    wil::event_set_scope_exit ensure_signaled =
        wil::SetEvent_scope_exit(redirect_event_handle.get());
 
    co_await keyInstance.RedirectActivationToAsync(args);

}

Container::Container()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
#endif
}

void Container::OnLaunched(winrt::Microsoft::UI::Xaml::LaunchActivatedEventArgs const& args)
{
    winrt::Windows::ApplicationModel::Activation::ActivationKind kind
        = args.UWPLaunchActivatedEventArgs().Kind();
 
    OutputFormattedMessage(L"OnLaunched: Kind=%s", KindString(kind).c_str());

    auto currentInstance = winrt::Microsoft::Windows::AppLifecycle::AppInstance::GetCurrent();

    if (currentInstance)
    {
        winrt::Microsoft::Windows::AppLifecycle::AppActivationArguments activationArgs
            = currentInstance.GetActivatedEventArgs();

        if (activationArgs)
        {
            winrt::Microsoft::Windows::AppLifecycle::ExtendedActivationKind extendedKind
                = activationArgs.Kind();

            OutputFormattedMessage(L"activationArgs.Kind=%s", KindString(extendedKind).c_str());
        
        }
    
    }

    oWindow = make<ContainerWindow>();
    oWindow.Activate();

}

void OnActivated(const winrt::Windows::Foundation::IInspectable&, const AppActivationArguments& args)
{
    int const arraysize = 4096;

    WCHAR szTmp[arraysize];

    size_t cbTmp = arraysize * sizeof(WCHAR);

    ExtendedActivationKind kind = args.Kind();

    if (kind == ExtendedActivationKind::File)
    {
        if (StringCbPrintf(szTmp, cbTmp, TEXT("OnActivated, count=%d"), activation_count++) == 0)
        {
            ReportFileArgs(szTmp, args);
        
        }
        else
        {
            ReportFileArgs(L"OnActivated", args);
        
        }
    
    }

}

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    void (WINAPI * XamlCheckProcessRequirements)();

    HMODULE module = ::LoadLibrary(L"Microsoft.ui.xaml.dll");

    if (module)
    {
        XamlCheckProcessRequirements = reinterpret_cast<decltype(XamlCheckProcessRequirements)>(GetProcAddress(module, "XamlCheckProcessRequirements"));
 
        if (XamlCheckProcessRequirements)
        {
            (*XamlCheckProcessRequirements)();

        }

        ::FreeLibrary(module);

    }

    winrt::init_apartment(winrt::apartment_type::single_threaded);
    
    oMessages = winrt::single_threaded_observable_vector<winrt::Windows::Foundation::IInspectable>();
    
    bool isRedirect = false;

    AppActivationArguments args = AppInstance::GetCurrent().GetActivatedEventArgs();

    ExtendedActivationKind kind = args.Kind();

    if (kind == ExtendedActivationKind::Launch)
    {
        ReportLaunchArgs(L"main", args);

    }
    else if (kind == ExtendedActivationKind::File)
    {
        ReportFileArgs(L"main", args);

        try
        {
            IFileActivatedEventArgs fileArgs = args.Data().as<IFileActivatedEventArgs>();
         
            if (fileArgs)
            {
                IStorageItem file{ fileArgs.Files().GetAt(0) };
            
                AppInstance keyInstance{ nullptr };
                keyInstance = AppInstance::FindOrRegisterForKey(file.Name());
                
                OutputFormattedMessage(L"Registered key = %s", keyInstance.Key().c_str());

                if (keyInstance.IsCurrent())
                {
                    OutputFormattedMessage(
                        L"IsCurrent=true; registered this instance for %s", 
                        file.Name().c_str());

                    activation_token = keyInstance.Activated([&keyInstance](const auto& sender, const AppActivationArguments& args)
                        { OnActivated(sender, args); } );

                    OutputMessage(L"Connected Activated event");

                }
                else
                {
                    isRedirect = true;

                    redirect_event_handle.create();

                    Redirect(keyInstance, args);

                    DWORD handleIndex = 0;

                    HANDLE rawHandle = redirect_event_handle.get();

                    if (CoWaitForMultipleObjects(CWMO_DEFAULT, INFINITE, 1, &rawHandle, &handleIndex) != 0)
                    {
                        OutputDebugString(L"Error waiting on event");

                    }

                }

            }

        }
        catch (...)
        {
            OutputDebugString(L"Error getting instance information");

        }

    }

    if (!isRedirect)
    {
        ::winrt::Microsoft::UI::Xaml::Application::Start([](auto&&)
            { 
                ::winrt::make<::winrt::MassEntropy::implementation::Container>(); 
            
                return;
            
            });

    }

    return 0;

}