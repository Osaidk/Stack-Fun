cmake_minimum_required(VERSION 3.12)
project(stackfun2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(stackfun2
        fake_picture.txt
        Flow_driver.c
        Linked_list.c
        stack_ll.h)
