#ifndef BEST_IMPROVEMENT
#define BEST_IMPROVEMENT

#include "Improvement.hpp"

struct BestImprovement : public Improvement {
    Permutation improve(const Instance& instance, const Permutation& p,
        Neighbourhood n);
};

#endif // BEST_IMPROVEMENT
