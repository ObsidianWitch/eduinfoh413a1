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
    src/Neighbourhood.cpp
    src/Neighbourhood.hpp
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

add_executable(test_neighbourhoods
    src/tests/neighbourhoods.cpp
    src/Neighbourhood.cpp
    src/Neighbourhood.hpp
)

add_executable(test_random_init
    src/tests/random_init.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Initialization.cpp
    src/Initialization.hpp
)

add_executable(test_string_matrix_permutation
    src/tests/string_matrix_permutation.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Initialization.cpp
    src/Initialization.hpp
    src/Instance.cpp
    src/Instance.hpp
)
