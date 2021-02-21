//
// Created by admin on 19.02.2021.
//

#include "FirstWindow.h"

bool FirstWindow::registered = false;
HINSTANCE FirstWindow::programInstanceHandle = NULL;

FirstWindow::FirstWindow()
{
    myWindowHandle = CreateWindowEx(
            0,                      //Optional window styles
            CLASS_NAME,
            L"Learn to program Windows",
            WS_OVERLAPPEDWINDOW,    //Window style

            //Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,        //Parent window
            NULL,       //Menu
            programInstanceHandle,  //instance handle
            NULL        //additional application data
    );
}

void FirstWindow::show(int showCommand)
{
    ShowWindow(myWindowHandle, showCommand);
}

bool FirstWindow::isCreated()
{
    return myWindowHandle != NULL;
}

void FirstWindow::setupClass()
{
    registerWindowClass();
}

void FirstWindow::registerWindowClass()
{
    if(!registered)
    {
        bool someBool = false;
        WNDCLASS wc = generateWindowClass();
        registered = RegisterClass(&wc);
    }
}

WNDCLASS FirstWindow::generateWindowClass()
{
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;
    return wc;
}

LRESULT CALLBACK FirstWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CLOSE:
            if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            // Else: User canceled. Do nothing.
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
