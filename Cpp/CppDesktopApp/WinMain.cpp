#include "pch.h"
#include "winrt/WinRTComponent.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace WinRTComponent;

int __stdcall wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    Class winrtComponentClass;

    init_apartment(apartment_type::single_threaded);
    ::MessageBoxW(::GetDesktopWindow(), winrtComponentClass.MyProperty().c_str(), L"Desktop App + WinRT Component", MB_OK);
}
