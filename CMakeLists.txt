cmake_minimum_required(VERSION 4.1)
project(Basic_Neural_Network)

set(CMAKE_CXX_STANDARD 20)

add_library(Basic_Neural_Network STATIC
        Matrix.cpp
        Matrix.h)
