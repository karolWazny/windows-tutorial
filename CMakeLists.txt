cmake_minimum_required(VERSION 3.17)
project(windows_tutorial)

set(CMAKE_CXX_STANDARD 17)

add_executable(windows_tutorial WIN32 main.cpp WindowTemplate.h FirstWindow.cpp FirstWindow.h basewin.h MainWindow.cpp MainWindow.h SafeRelease.h)