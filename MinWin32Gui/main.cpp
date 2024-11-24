//
//  main.cpp
//  MinWin32Gui
//
//  created by yu2924 on 2024-11-24
//

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

extern "C" void WinMainCRTStartup()
{
	static const WCHAR msg[] = L"Hello World\n";
	MessageBoxW(NULL, msg, L"", MB_ICONINFORMATION | MB_OK);
}
