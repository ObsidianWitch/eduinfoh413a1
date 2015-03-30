% Implementation exercise 1

# Linear Ordering Problem
<!-- TODO try to retrieve more recent slides -->

Examples :
* Sport tournament ranking
* archeology
~~~
layers examples

- - - -
B B C B
A C A A
C

(read: col over line, e.g., A is over C -> happens 1 time)
  A B C
A - 0 1
B 2 - 2
C 0 0 -
~~~

**N.B.** only the upper right part of the matrix is part of the solution -> optimization possible (save memory and time at initialization) by not allocating memory for the unused part of the matrix.

* transpose : 4x4 matrix, -> only 3 elements change the value (common pattern) -> only use these to recompute the value

* the same seed should be used for one instance -> possible solution: generate seed based on filename

# Reading options

* getopt
* lopOpts_t struct
* lopOpts_t can be initialized with emptyLopOpts ([source](http://goo.gl/21VvQQ))
* http://www.ibm.com/developerworks/aix/library/au-unix-getopt.html
