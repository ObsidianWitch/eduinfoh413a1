#ifndef FIRST_IMPROVEMENT
#define FIRST_IMPROVEMENT

#include "Improvement.hpp"

struct FirstImprovement : public Improvement {
    Permutation improve(const Instance& instance, const Permutation& p,
        Neighbourhood n);
};

#endif // FIRST_IMPROVEMENT
