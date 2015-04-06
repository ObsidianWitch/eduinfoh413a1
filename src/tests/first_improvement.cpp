#include <iostream>
#include <cstdlib>
#include <cassert>

#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "Permutation.hpp"
#include "Instance.hpp"

int main() {
    Instance instance("../instances/test2");
    Permutation p(instance.size());
    std::cout << "instance matrix" << std::endl
              << instance << std::endl;
    std::cout << "score: " << instance.evaluate(p) << std::endl << std::endl;
    
    Neighbourhood n(instance.size(), Neighbourhood::TRANSPOSE);
    
    FirstImprovement fi(instance, n);
    Permutation improvedP = fi.improve(p);
    
    std::cout << "permutation instance matrix" << std::endl
              << instance.toStringMatrixPermutation(improvedP) << std::endl;
    std::cout << "score: " << instance.evaluate(improvedP) << std::endl
              << std::endl;
              
    improvedP = fi.improve(improvedP);

    std::cout << "permutation instance matrix" << std::endl
            << instance.toStringMatrixPermutation(improvedP) << std::endl;
    std::cout << "score: " << instance.evaluate(improvedP) << std::endl;

    return EXIT_SUCCESS;
}
