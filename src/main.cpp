#include <iostream>
#include <cstdlib>

#include "rules/Initialization/RandomInitialization.hpp"
#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "IterativeImprovement.hpp"
#include "GlobalArgs.hpp"
#include "Instance.hpp"

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

    Instance instance(g.filePath.c_str());
    RandomInitialization init(instance.totalSum(), instance.size());
    Neighbourhood n(instance.size(), Neighbourhood::TRANSPOSE);
    FirstImprovement fi(instance, n);
    
    IterativeImprovement ii(instance, init, fi);
    ii.run();

    return EXIT_SUCCESS;
}
