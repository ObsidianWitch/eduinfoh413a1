#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Permutation.hpp"
#include "Initialization.hpp"

int main() {
    Instance instance("../instances/test2");
    std::cout << "instance matrix" << std::endl
              << instance.matrix() << std::endl << std::endl;
    
    CWInit init(instance);
    Permutation p = init.generateInitialization();
    
    std::cout << "permutation" << std::endl << p;
    
    std::cout << "instance matrix with permutation"  << std::endl;
    instance.printMatrixPermutation(p);
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
