#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Instance.hpp"
#include "Permutation.hpp"
#include "rules/Initialization/CWInitialization.hpp"

int main() {
    Instance instance("../instances/test3");
    std::cout << "instance matrix" << std::endl
              << instance.matrix() << std::endl << std::endl;
    
    CWInitialization init(instance);
    Permutation p = init.generateInitialization();
    
    std::cout << "permutation" << std::endl << p;
    
    std::cout << "instance matrix with permutation"  << std::endl
              << instance.toStringMatrixPermutation(p)
              << std::endl;
    
    return EXIT_SUCCESS;
}
