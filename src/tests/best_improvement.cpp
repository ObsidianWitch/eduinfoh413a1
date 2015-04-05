#include <iostream>
#include <cstdlib>
#include <cassert>

#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/BestImprovement.hpp"
#include "Permutation.hpp"
#include "Instance.hpp"

int main() {
    Instance instance("../instances/test1");
    Permutation p(instance.size());
    std::cout << "instance matrix" << std::endl
              << instance << std::endl;
    std::cout << "score: " << instance.evaluate(p) << std::endl << std::endl;
    
    Neighbourhood n(instance.size(), Neighbourhood::TRANSPOSE);
    
    BestImprovement bi;
    Permutation improvedP = bi.improve(instance, p, n);
    
    std::cout << "permutation instance matrix" << std::endl
              << instance.toStringMatrixPermutation(improvedP) << std::endl;
    std::cout << "score: " << instance.evaluate(improvedP) << std::endl
              << std::endl;
              
    improvedP = bi.improve(instance, improvedP, n);

    std::cout << "permutation instance matrix" << std::endl
            << instance.toStringMatrixPermutation(improvedP) << std::endl;
    std::cout << "score: " << instance.evaluate(improvedP) << std::endl;

    return EXIT_SUCCESS;
}
