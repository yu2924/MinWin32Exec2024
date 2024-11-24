//
//  main.cpp
//  MinWin32Con
//
//  created by yu2924 on 2024-11-24
//

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

extern "C" void mainCRTStartup()
{
	static const WCHAR msg[] = L"Hello World\n";
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), msg, lstrlenW(msg), nullptr, nullptr);
}
