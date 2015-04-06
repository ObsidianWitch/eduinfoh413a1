#ifndef BEST_IMPROVEMENT
#define BEST_IMPROVEMENT

#include "Improvement.hpp"

class BestImprovement : public Improvement {
public:
    BestImprovement(const Instance& instance, Neighbourhood n);
    
    Permutation improve(const Permutation& p);
};

#endif // BEST_IMPROVEMENT
