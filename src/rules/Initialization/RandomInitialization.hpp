#ifndef RANDOM_INITIALIZATION_HPP
#define RANDOM_INITIALIZATION_HPP

#include <random>
#include "Initialization.hpp"

class RandomInitialization : public Initialization {
public:
    RandomInitialization(long int seed, unsigned size);
    
    Permutation generateInitialization();
    
private:
    std::mt19937 randomEngine_;
    unsigned size_;
};

#endif // RANDOM_INITIALIZATION_HPP
