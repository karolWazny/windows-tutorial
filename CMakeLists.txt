cmake_minimum_required(VERSION 3.17)
project(windows_tutorial)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        )

include_directories(windows_lib)
add_subdirectory(windows_lib)

add_executable(windows_tutorial WIN32 ${SOURCE_FILES})
target_link_libraries(windows_tutorial windows_lib)