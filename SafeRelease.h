//
// Created by admin on 20.02.2021.
//

#ifndef WINDOWS_TUTORIAL_SAFERELEASE_H
#define WINDOWS_TUTORIAL_SAFERELEASE_H

template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}


#endif //WINDOWS_TUTORIAL_SAFERELEASE_H
