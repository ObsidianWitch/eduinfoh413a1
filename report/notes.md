% Implementation exercise 1

# Linear Ordering Problem

* only the upper right part of the matrix is part of the solution -> possible
optimization?

* transpose : 4x4 matrix, -> only 3 elements change the value (common pattern)
-> only use these to recompute the value

* the same seed should be used for one instance -> possible solutions: generate
seed based on filename or on the instance size

# Reading options

* getopt
* lopOpts_t struct
* lopOpts_t can be initialized with emptyLopOpts ([source](http://goo.gl/21VvQQ))
* http://www.ibm.com/developerworks/aix/library/au-unix-getopt.html
