cmake_minimum_required(VERSION 3.8)
project(algorithms)

set(CMAKE_C_STANDARD 99)

add_executable(test_List test_List.c List.h List.c)
add_executable(test_dlist test_dlist.c dlist.h dlish.c)

