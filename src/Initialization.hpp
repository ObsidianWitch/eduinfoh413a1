#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <random>
#include "Permutation.hpp"
#include "Instance.hpp"

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

class CWInit {
public:
    CWInit(const Instance& instance);
    
    Permutation generateInitialization();
    
private:
    unsigned evaluateRows(const Permutation& permutation, unsigned step);
    long int evaluateRow(const Permutation& permutation, unsigned row,
        unsigned step);
    
    const Instance& instance_;
};

#endif // INITIALIZATION_HPP
