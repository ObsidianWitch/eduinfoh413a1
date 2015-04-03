cmake_minimum_required(VERSION 2.6)
project(A1)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -O3")

include_directories(src)

add_executable(lop
    src/main.cpp
    src/Instance.cpp
    src/Instance.hpp
    src/Permutation.cpp
    src/Permutation.hpp
)

add_executable(test_load_instance
    src/tests/load_instance.cpp
    src/Instance.cpp
    src/Instance.hpp
)

add_executable(test_permutation
    src/tests/permutation.cpp
    src/Permutation.cpp
    src/Permutation.hpp
)
