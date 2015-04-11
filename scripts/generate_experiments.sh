#!/bin/sh
./generate_experiments_one.lua lop random first transpose &
./generate_experiments_one.lua lop cw first transpose &
./generate_experiments_one.lua lop random best transpose &
./generate_experiments_one.lua lop cw best transpose &

#./generate_experiments_one.lua lop random first exchange > /dev/null &
#./generate_experiments_one.lua lop cw first exchange > /dev/null &
#./generate_experiments_one.lua lop random best exchange > /dev/null &
#./generate_experiments_one.lua lop cw best exchange > /dev/null &

#./generate_experiments_one.lua lop random first insert > /dev/null &
#./generate_experiments_one.lua lop cw first insert > /dev/null &
#./generate_experiments_one.lua lop random best insert > /dev/null &
#./generate_experiments_one.lua lop cw best insert > /dev/null &

#./generate_experiments_one.lua vnd tei > /dev/null &
#./generate_experiments_one.lua vnd tie > /dev/null &
