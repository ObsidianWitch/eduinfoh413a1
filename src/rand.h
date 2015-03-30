#ifndef _RAND_H_
#define _RAND_H_

/* constants for a pseudo-random number generator, taken from
 * Numerical Recipes in C book --- never trust the standard C random
 * number generator */
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836

extern long int Seed; /* seed for the random number generator */

int rand0N(int limit); // TODO uh?

extern double ran01( long *idum );

extern int randInt(int minimum, int maximum);

extern long int * generate_random_vector(long int dim );

#endif // _RAND_H_
