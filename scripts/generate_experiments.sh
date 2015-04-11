#!/bin/sh
./generate_experiments_one.lua lop random first transpose &
./generate_experiments_one.lua lop cw first transpose &
./generate_experiments_one.lua lop random best transpose &
./generate_experiments_one.lua lop cw best transpose &

./generate_experiments_one.lua lop random first exchange &
./generate_experiments_one.lua lop cw first exchange &
./generate_experiments_one.lua lop random best exchange &
./generate_experiments_one.lua lop cw best exchange &

./generate_experiments_one.lua lop random first insert &
./generate_experiments_one.lua lop cw first insert &
./generate_experiments_one.lua lop random best insert &
./generate_experiments_one.lua lop cw best insert &

./generate_experiments_one.lua vnd tei &
./generate_experiments_one.lua vnd tie &
