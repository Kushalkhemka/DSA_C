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
        doubly_linked_list.cpp
        stack_using_LL.c
        balanced_paranthesis.c
        K_stack_using_array.c
        Infinix_To_Postfix_With_Eval.c
        Infix_To_Prefix_With_Eval.c
        Queue_using_LL.c
)
