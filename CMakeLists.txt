cmake_minimum_required(VERSION 3.10)
project(grafe)

set(CMAKE_CXX_STANDARD 11)

add_executable(grafe main.cpp edge.cpp edge.h graph.cpp graph.h digraph.cpp digraph.h)