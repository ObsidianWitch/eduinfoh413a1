cmake_minimum_required(VERSION 2.6)
project(A1)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -O3")

include_directories(src)

add_executable(lop
    src/IterativeImprovement/main_II.cpp
    src/Instance.cpp
    src/Instance.hpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/IterativeImprovement/GlobalArgsII.cpp
    src/IterativeImprovement/GlobalArgsII.hpp
    src/IterativeImprovement/IterativeImprovement.cpp
    src/IterativeImprovement/IterativeImprovement.hpp
    src/rules/RulesFactory.cpp
    src/rules/RulesFactory.hpp
    src/rules/Neighbourhood/Neighbourhood.cpp
    src/rules/Neighbourhood/Neighbourhood.hpp
    src/rules/Neighbourhood/TransposeNeighbourhood.cpp
    src/rules/Neighbourhood/TransposeNeighbourhood.hpp
    src/rules/Neighbourhood/ExchangeNeighbourhood.cpp
    src/rules/Neighbourhood/ExchangeNeighbourhood.hpp
    src/rules/Neighbourhood/InsertNeighbourhood.cpp
    src/rules/Neighbourhood/InsertNeighbourhood.hpp
    src/rules/Pivoting/Improvement.hpp
    src/rules/Pivoting/FirstImprovement.cpp
    src/rules/Pivoting/FirstImprovement.hpp
    src/rules/Pivoting/BestImprovement.cpp
    src/rules/Pivoting/BestImprovement.hpp
    src/rules/Initialization/Initialization.hpp
    src/rules/Initialization/CWInitialization.cpp
    src/rules/Initialization/CWInitialization.hpp
    src/rules/Initialization/RandomInitialization.cpp
    src/rules/Initialization/RandomInitialization.hpp
)

add_executable(vnd
    src/VariableNeighbourhoodDescent/main_VND.cpp
    src/Instance.cpp
    src/Instance.hpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/VariableNeighbourhoodDescent/GlobalArgsVND.cpp
    src/VariableNeighbourhoodDescent/GlobalArgsVND.hpp
    src/VariableNeighbourhoodDescent/VariableNeighbourhoodDescent.cpp
    src/VariableNeighbourhoodDescent/VariableNeighbourhoodDescent.hpp
    src/rules/RulesFactory.cpp
    src/rules/RulesFactory.hpp
    src/rules/Neighbourhood/TransposeNeighbourhood.cpp
    src/rules/Neighbourhood/TransposeNeighbourhood.hpp
    src/rules/Neighbourhood/ExchangeNeighbourhood.cpp
    src/rules/Neighbourhood/ExchangeNeighbourhood.hpp
    src/rules/Neighbourhood/InsertNeighbourhood.cpp
    src/rules/Neighbourhood/InsertNeighbourhood.hpp
    src/rules/Neighbourhood/Neighbourhood.cpp
    src/rules/Neighbourhood/Neighbourhood.hpp
    src/rules/Pivoting/Improvement.hpp
    src/rules/Pivoting/FirstImprovement.cpp
    src/rules/Pivoting/FirstImprovement.hpp
    src/rules/Pivoting/BestImprovement.cpp
    src/rules/Pivoting/BestImprovement.hpp
    src/rules/Initialization/Initialization.hpp
    src/rules/Initialization/CWInitialization.cpp
    src/rules/Initialization/CWInitialization.hpp
    src/rules/Initialization/RandomInitialization.cpp
    src/rules/Initialization/RandomInitialization.hpp
)

add_executable(test_load_instance
    src/tests/load_instance.cpp
    src/Instance.cpp
    src/Instance.hpp
    src/Permutation.cpp
    src/Permutation.hpp
)

add_executable(test_permutation
    src/tests/permutation.cpp
    src/Permutation.cpp
    src/Permutation.hpp
)

add_executable(test_neighbourhoods
    src/tests/neighbourhoods.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/rules/Neighbourhood/Neighbourhood.hpp
    src/rules/Neighbourhood/Neighbourhood.cpp
    src/rules/Neighbourhood/TransposeNeighbourhood.cpp
    src/rules/Neighbourhood/TransposeNeighbourhood.hpp
    src/rules/Neighbourhood/ExchangeNeighbourhood.cpp
    src/rules/Neighbourhood/ExchangeNeighbourhood.hpp
    src/rules/Neighbourhood/InsertNeighbourhood.cpp
    src/rules/Neighbourhood/InsertNeighbourhood.hpp
)

add_executable(test_random_init
    src/tests/random_init.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Instance.cpp
    src/Instance.hpp
    src/rules/Initialization/RandomInitialization.cpp
    src/rules/Initialization/RandomInitialization.hpp
)

add_executable(test_string_matrix_permutation
    src/tests/string_matrix_permutation.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Instance.cpp
    src/Instance.hpp
)

add_executable(test_evaluate
    src/tests/evaluate.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Instance.cpp
    src/Instance.hpp
)

add_executable(test_first_improvement
    src/tests/first_improvement.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Instance.cpp
    src/Instance.hpp
    src/rules/Neighbourhood/TransposeNeighbourhood.cpp
    src/rules/Neighbourhood/TransposeNeighbourhood.hpp
    src/rules/Neighbourhood/Neighbourhood.cpp
    src/rules/Neighbourhood/Neighbourhood.hpp
    src/rules/Pivoting/FirstImprovement.cpp
    src/rules/Pivoting/FirstImprovement.hpp
)

add_executable(test_best_improvement
    src/tests/best_improvement.cpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/Instance.cpp
    src/Instance.hpp
    src/rules/Neighbourhood/TransposeNeighbourhood.cpp
    src/rules/Neighbourhood/TransposeNeighbourhood.hpp
    src/rules/Neighbourhood/Neighbourhood.cpp
    src/rules/Neighbourhood/Neighbourhood.hpp
    src/rules/Pivoting/BestImprovement.cpp
    src/rules/Pivoting/BestImprovement.hpp
)

add_executable(test_cw_init
    src/tests/cw_init.cpp
    src/Instance.cpp
    src/Instance.hpp
    src/Permutation.cpp
    src/Permutation.hpp
    src/rules/Initialization/CWInitialization.cpp
    src/rules/Initialization/CWInitialization.hpp
)
