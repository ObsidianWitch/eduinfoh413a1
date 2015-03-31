% Implementation exercise 1

# Linear Ordering Problem

* only the upper right part of the matrix is part of the solution -> possible
optimization?

* transpose : 4x4 matrix, -> only 3 elements change the value (common pattern)
-> only use these to recompute the value

* the same seed should be used for one instance -> possible solutions: generate
seed based on filename or on the instance size

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
