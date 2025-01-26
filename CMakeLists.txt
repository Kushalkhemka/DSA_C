cmake_minimum_required(VERSION 3.29)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA main.cpp
        "Sparsed Matrix.c"
        Queue_Using_Circular_Array.c)
