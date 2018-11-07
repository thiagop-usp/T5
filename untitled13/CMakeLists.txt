cmake_minimum_required(VERSION 3.12)
project(untitled13)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(untitled13
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/untitled13
        cmake-build-debug/untitled13.cbp
        CMakeLists.txt
        double_linked_list.c
        double_linked_list.h
        main.c)
