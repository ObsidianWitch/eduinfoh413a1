#ifndef IMPROVEMENT
#define IMPROVEMENT

#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "Instance.hpp"
#include "Permutation.hpp"

class Improvement {
public:
    Improvement(const Instance& instance, Neighbourhood n) :
        instance_(instance), n_(n)
    {}
    virtual ~Improvement() {}
    
    virtual Permutation improve(const Permutation& p) = 0;
        
protected:
    const Instance& instance_;
    Neighbourhood n_;
};

#endif // IMPROVEMENT
