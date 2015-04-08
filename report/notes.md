% Implementation exercise 1

# Linear Ordering Problem

* only the upper right part of the matrix is part of the solution -> possible
optimization?

* transpose : 4x4 matrix, -> only 3 elements change the value (common pattern)
-> only use these to recompute the value

* the same seed should be used for one instance -> possible solutions: generate
seed based on filename or on the instance size

# Neighbourhoods

<http://goo.gl/qIaKpp>

* Transpose Neighbourhood $N_t$: 2 permutations $\phi$, $\phi'$ are transpose
neighbourhoods iff one can be obtained from the other by swapping the positions
of 2 adjacent jobs. $|N_t| = n-1$.

* Exchange Neighbourhood $N_e$: 2 permutations $\phi$, $\phi'$ are 2-exchange
neighbourhood iff one can be obtained from the other by swapping 2 elements
i and j (i != j) regardless of their adjacency. $|N_e| = n*(n-1)/2$.

* Insert Neighbourhood $N_i$: all permutations that can be obtained by removing
an element at the ith position and inserting it in the jth position (i != j).
$|N_i| = (n-1)^2$.

# Algorithm configuration

* 12 combination
* pivoting rule (-p)
    * first improvement
    * best improvement
* neighbourhood (-n)
    * transpose
    * exchange
    * insert
* init solution (-i)
    * random permutation
    * CW heuristic

# Parse Command Line Arguments

* getopt
* lopOpts_t struct
* lopOpts_t can be initialized with emptyLopOpts ([source](http://goo.gl/21VvQQ))
* <http://www.ibm.com/developerworks/aix/library/au-unix-getopt.html>
* <http://www.boost.org/doc/libs/1_57_0/doc/html/program_options.html>

# RNG

* <https://en.wikipedia.org/wiki/C%2B%2B11#Extensible_random_number_facility>
* <http://en.cppreference.com/w/cpp/numeric/random>
* <http://www.stroustrup.com/#std-random>

# LOLIB

"LOLIB is a library of sample instances for the linear ordering problem. LOLIB
includes data as well as optimum solution values."

<http://www.optsicom.es/lolib/>

# Architecture Ideas

* input (e.g. --first --transpose --rand instance) --> program -->
    * AlgorithmBuilder ab();
    * ab.setPivotingRule(String pivotingRule)
        .setNeighborhood(String neighborhood)
        .setInitialSolution(String initSolution)
        .setFilePath(String filePath);
    * Algorithm a = ab.build();
    * a.run();

# Scripts

## generate_experiments

~~~
instance_name score best_knwon_score deviation computation_time
N-be75eec_150 2850321 3482828 18.160730303076 1.10763
N-be75eec_250 7456782 8893533 16.155008363943 7.79982
N-be75np_150 5991561 7174325 16.486066633446 0.997437
N-be75np_250 14820463 17814072 16.804742902128 7.66058
~~~

## compute_averages

~~~
experiment_name average_deviation computation_time_sum computation_time_average
ii_cw_best_exchange 17.277346692163 333 4.2692307692308
ii_cw_best_insertion 17.084249592579 321 4.1153846153846
ii_cw_best_transpose 17.549047663734 243 3.1153846153846
~~~
