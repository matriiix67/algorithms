cmake_minimum_required(VERSION 3.8)
project(algorithms)

set(CMAKE_C_STANDARD 99)

add_executable(test_List test_List.c list.h list.c)
add_executable(test_dlist test_dlist.c dlist.h dlish.c)
add_executable(test_clist test_clist.c clist.h clist.c)
add_executable(test_stack test_stack.c stack.h stack.c)
add_executable(test_queue test_queue.c queue.h queue.c)
add_executable(test_chtbl.c chtbl.c chtbl.h)
add_executable(test_ohtbl.c ohtbl.h ohtbl.c)

add_executable(test_sort.c sort.h sort.c)
