//
// Created by admin on 19.02.2021.
//

#ifndef WINDOWS_TUTORIAL_FIRSTWINDOW_H
#define WINDOWS_TUTORIAL_FIRSTWINDOW_H
#include "WindowTemplate.h"

class FirstWindow {
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    FirstWindow();
    static void setupClass();
    void show(int);
    bool isCreated();
private:
    static WNDCLASS generateWindowClass();
    static void registerWindowClass();
    static constexpr wchar_t CLASS_NAME[] = L"First Window Class";
    static HINSTANCE programInstanceHandle;
    static bool registered;
    HWND myWindowHandle {};
};

#endif //WINDOWS_TUTORIAL_FIRSTWINDOW_H