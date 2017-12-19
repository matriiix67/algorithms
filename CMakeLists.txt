cmake_minimum_required(VERSION 3.8)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_sort test_sort.cpp Sort.h Sort.cpp)
add_executable(test_graph test_graph.cpp Graph.h Graph.cpp)
add_executable(test_depth_first_paths test_depth_first_paths.cpp DepthFirstPaths.h DepthFirstPaths.cpp Graph.h Graph.cpp)
