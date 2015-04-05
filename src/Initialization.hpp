#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <random>
#include "Permutation.hpp"

struct Initialization {
    virtual Permutation generateInitialization() = 0;
};

class RandomInit : public Initialization {
public:
    RandomInit(long int seed, unsigned size);
    
    Permutation generateInitialization();
    
private:
    std::mt19937 randomEngine_;
    unsigned size_;
};

#endif // INITIALIZATION_HPP
