//
// Created by admin on 19.02.2021.
//

#ifndef WINDOWS_TUTORIAL_WINDOWTEMPLATE_H
#define WINDOWS_TUTORIAL_WINDOWTEMPLATE_H
#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

template <typename T>
class WindowTemplate
{
public:
static LRESULT CALLBACK windowProc();
static void registerWindowType();
protected:
WindowTemplate(WNDCLASS);
private:
static bool registered;
static const WNDCLASS wc;
};

template <typename T>
WindowTemplate<T>::WindowTemplate(WNDCLASS windowClass)
{
    if(!registered)
    {
        registerWindowType();
    }

}

template <typename T>
void WindowTemplate<T>::registerWindowType()
{
    RegisterClass(&wc);
    registered = true;
}



#endif //WINDOWS_TUTORIAL_WINDOWTEMPLATE_H
