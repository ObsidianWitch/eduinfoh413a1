# Heuristic Optimization 1st assignment : Iterative Improvement

## Description

<!-- TODO -->

## Compilation

~~~
> mkdir out
> cd out
> cmake ..
> make lop vnd
~~~

## Run on one instance

~~~
Usage:./lop -i <initialization_rule (cw|random)>
	        -p <pivoting_rule (first|best)>
	        -n <neighbourhood (transpose|exchange|insertion)>
	        -f <instance_file>

> ./lop -i cw -p first -n transpose -f ../instances/N-be75eec_250
~~~
