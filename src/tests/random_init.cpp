#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Permutation.hpp"
#include "Initialization.hpp"

int main() {
    RandomInit init(std::mt19937::default_seed, 10);
    Permutation p = init.generateInitialization();
    
    std::cout << p;
    
    return EXIT_SUCCESS;
}
