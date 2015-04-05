#ifndef IMPROVEMENT
#define IMPROVEMENT

#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "Instance.hpp"
#include "Permutation.hpp"

struct Improvement {
    virtual Permutation improve(const Instance& instance, const Permutation& p,
        Neighbourhood n) = 0;
};

#endif // IMPROVEMENT
