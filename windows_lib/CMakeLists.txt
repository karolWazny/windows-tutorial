project(windows_lib)

set(HEADER_FILES
        FirstWindow.h
        MainWindow.h
        SafeRelease.h
        WindowTemplate.h
        basewin.h
        )

set(SOURCE_FILES
        FirstWindow.cpp
        MainWindow.cpp
        )

add_library(windows_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})