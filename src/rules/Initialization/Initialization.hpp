#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include "Permutation.hpp"

struct Initialization {
    virtual Permutation generateInitialization() = 0;
};

#endif // INITIALIZATION_HPP
