#ifndef FIRST_IMPROVEMENT
#define FIRST_IMPROVEMENT

#include "Improvement.hpp"

class FirstImprovement : public Improvement {
public:
    FirstImprovement(const Instance& instance, Neighbourhood n);
    
    Permutation improve(const Permutation& p);
};

#endif // FIRST_IMPROVEMENT
