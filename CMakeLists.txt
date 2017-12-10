cmake_minimum_required(VERSION 3.8)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_sort test_sort.cpp Sort.h Sort.cpp)
