cmake_minimum_required(VERSION 3.29)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA main.cpp
        "Sparsed Matrix.c"
        Queue_with_Circular_Array.c
        Linked_list.c
        Double_Stack_Array.c
        Stack_Using_Array.c
        "advanced_linked_list.cpp"
        doubly_linked_list.cpp
        doubly_linked_list.cpp)
