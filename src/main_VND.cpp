#include <iostream>
#include <cstdlib>
#include <chrono>

#include "rules/Initialization/CWInitialization.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "rules/RulesFactory.hpp"
#include "IterativeImprovement.hpp"
#include "GlobalArgsVND.hpp"
#include "Instance.hpp"

int main(int argc, char *argv[]) {
    using namespace std::chrono;
    
    // Arguments handling
    GlobalArgsVND g(argv[0]);
    
    if (argc < 5) {
        std::cout << "Missing argument" << std::endl;
        g.printHelp();
        return EXIT_FAILURE;
    }

    g.retrieve(argc, argv);
    g.checkArgs();
    
    // Algorithm dependencies
    Instance instance(g.filePath.c_str());
    CWInitialization initialization(instance);
    /* FIXME Neighbourhood* neighbourhood = RulesFactory::getNeighbourhood(
        g.neighbourhood, instance.size()
    );*/
    // FIXME FirstImprovement improvement(instance, *neighbourhood);
    
    // VND algorithm
    // FIXME IterativeImprovement ii(instance, initialization, improvement);
    auto start = high_resolution_clock::now();
    // FIXME ii.run();
    duration<double> timeElapsed = high_resolution_clock::now() - start;
    std::cout << "Time elapsed: " << timeElapsed.count() << " s" << std::endl;
    
    // Memory handling
    // FIXME delete neighbourhood;

    return EXIT_SUCCESS;
}
