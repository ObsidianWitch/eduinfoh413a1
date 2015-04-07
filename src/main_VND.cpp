#include <iostream>
#include <cstdlib>
#include <chrono>

#include "IterativeImprovement.hpp"
#include "rules/RulesFactory.hpp"
#include "GlobalArgs.hpp"
#include "Instance.hpp"

int main(int argc, char *argv[]) {
    using namespace std::chrono;
    
    // Arguments handling
    GlobalArgs g(argv[0]);
    
    if (argc < 9) {
        std::cout << "Missing argument" << std::endl;
        g.printHelp();
        return EXIT_FAILURE;
    }

    g.retrieve(argc, argv);
    g.checkArgs();
    
    // Algorithm dependencies
    Instance instance(g.filePath.c_str());
    CWInitialization initialization(instance);
    Neighbourhood* neighbourhood = RulesFactory::getNeighbourhood(
        g.neighbourhood, instance.size()
    );
    FirstImprovement improvement(instance, *neighbourhood);
    
    // IterativeImprovement algorithm
    IterativeImprovement ii(instance, *initialization, *improvement);
    auto start = high_resolution_clock::now();
    ii.run();
    duration<double> timeElapsed = high_resolution_clock::now() - start;
    std::cout << "Time elapsed: " << timeElapsed.count() << " s" << std::endl;
    
    // Memory handling
    delete initialization;
    delete neighbourhood;
    delete improvement;

    return EXIT_SUCCESS;
}
