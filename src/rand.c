#include <stdlib.h>

#include "rand.h"
#include "utilities.h"

long int Seed; // TODO check

/**
 * FUNCTION:      returns a pseudo-random number
 * INPUT:         a pointer to the seed variable
 * OUTPUT:        a pseudo-random number uniformly distributed in [0,1]
 * (SIDE)EFFECTS: changes the value of seed
*/
double ran01( long *idum ) {
    long k;
    double ans;

    k =(*idum)/IQ;
    *idum = IA * (*idum - k * IQ) - IR * k;
    if (*idum < 0 ) { *idum += IM; }
    ans = AM * (*idum);

    return ans;
}

/**
 * Return random integer in the (inclusive) range [minimum, maximum].
 */
int randInt(int minimum, int maximum) {
    return ( (int)(ran01(&Seed)*(maximum - minimum + 1)) + minimum );
}

/**
 * Generates a random vector, quick and dirty.
 */
long int * generate_random_vector(long int dim) {
    long int *random_vector;
    int i, help, node, tot_assigned = 0;
    double rnd;

    random_vector = (long int *)malloc(dim * sizeof(long int));

    if (!random_vector) {
        fatal("Error on random_vector malloc\n");
    }

    for ( i = 0 ; i < dim; i++) {
        random_vector[i] = i;
    }

    for ( i = 0 ; i < dim ; i++ ) {
        /* find (randomly) an index for a free unit */
        rnd  = ran01 ( &Seed );
        node = (long int) (rnd  * (dim - tot_assigned));
        help = random_vector[i];
        random_vector[i] = random_vector[i+node];
        random_vector[i+node] = help;
        tot_assigned++;
    }

    return random_vector;
}
