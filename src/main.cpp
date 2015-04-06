#include <iostream>
#include <cstdlib>

#include "rules/Initialization/RandomInitialization.hpp"
#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "GlobalArgs.hpp"
#include "Instance.hpp"

void algorithm(const char* filePath) {
    Instance instance(filePath);
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
}

int main(int argc, char *argv[]) {
    GlobalArgs g(argv[0]);
    
    if (argc < 9) {
        std::cout << "Missing argument" << std::endl;
        g.printHelp();
        return EXIT_FAILURE;
    }

    g.retrieve(argc, argv);
    g.checkArgs();

    std::cout << g.init << " " << g.pivoting << " " << g.neighbourhood << " "
              << g.filePath << std::endl;

    algorithm(g.filePath.c_str());

    return EXIT_SUCCESS;
}
