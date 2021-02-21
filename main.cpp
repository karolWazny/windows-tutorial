#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include "FirstWindow.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR cCmdLine, int nCmdShow)
{
    FirstWindow::setupClass();
    FirstWindow window;

    if(!window.isCreated())
    {
        return 0;
    }

    window.show(nCmdShow);

    // Run the message loop

    MSG msg = {};
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
