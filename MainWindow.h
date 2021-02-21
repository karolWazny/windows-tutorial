//
// Created by admin on 20.02.2021.
//
#ifndef WINDOWS_TUTORIAL_MAINWINDOW_H
#define WINDOWS_TUTORIAL_MAINWINDOW_H

#ifndef UNICODE
#define UNICODE
#endif

#include "basewin.h"
#include <d2d1.h>
#pragma comment(lib, "d2d1")

class MainWindow : public BaseWindow<MainWindow>
{
    ID2D1Factory            *pFactory;
    ID2D1HwndRenderTarget   *pRenderTarget;
    ID2D1SolidColorBrush    *pBrush;
    D2D1_ELLIPSE            ellipse;

    void    CalculateLayout();
    HRESULT CreateGraphicsResources();
    void    DiscardGraphicsResources();
    void    OnPaint();
    void    Resize();

public:

    MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL)
    {
    }

    PCWSTR  ClassName() const { return L"Circle Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif //WINDOWS_TUTORIAL_MAINWINDOW_H
