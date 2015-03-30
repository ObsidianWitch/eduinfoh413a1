cmake_minimum_required(VERSION 2.6)
project(A1)

SET(CMAKE_C_COMPILER "gcc")
SET(CMAKE_C_FLAGS "-Wall -Wextra -std=c99 -O3")

include_directories(src)

add_executable(lop
    src/main.c
    src/instance.c
    src/instance.h
    src/optimization.c
    src/optimization.h
    src/timer.c
    src/timer.h
    src/utilities.c
    src/utilities.h
    src/options.c
    src/options.h
)
