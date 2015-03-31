cmake_minimum_required(VERSION 2.6)
project(A1)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -O3")

include_directories(src)

add_executable(lop
    src/main.cpp
)
