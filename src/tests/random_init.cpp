#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Permutation.hpp"
#include "rules/Initialization/RandomInitialization.hpp"

int main() {
    RandomInitialization init(std::mt19937::default_seed, 10);
    Permutation p = init.generateInitialization();
    
    std::cout << p;
    
    return EXIT_SUCCESS;
}
