cmake_minimum_required(VERSION 3.29)
project(double_linked_circular_list C)

set(CMAKE_C_STANDARD 23)

add_executable(double_linked_circular_list double_linked_circular_list.c double_linked_circular_list.h main.c)