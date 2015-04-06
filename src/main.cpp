#include <iostream>
#include <cstdlib>
#include "rules/Initialization/RandomInitialization.hpp"
#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "Instance.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <instance_file>" << std::endl;
        return EXIT_FAILURE;
    }

    Instance instance(argv[1]);
    RandomInitialization init(instance.totalSum(), instance.size());
    Neighbourhood n(instance.size(), Neighbourhood::TRANSPOSE);
    FirstImprovement fi(instance, n);
    
    Permutation p(instance.size());
    std::cout << "instance size: " << instance.size() << std::endl
              << "instance score: " << instance.evaluate(p) << std::endl
              << "seed: " << instance.totalSum() << std::endl;

    bool localOptimum = false;
    Permutation p1 = init.generateInitialization();
    std::cout << "initial solution (score: " << instance.evaluate(p1) << "): "
              << p1 << std::endl;
    
    while (!localOptimum) {
        Permutation p2 = fi.improve(p1);
        
        localOptimum = (p1 == p2);
        p1 = p2;
    }
    std::cout << "final solution (score: " << instance.evaluate(p1) << "): "
              << p1 << std::endl;

    return EXIT_SUCCESS;
}
