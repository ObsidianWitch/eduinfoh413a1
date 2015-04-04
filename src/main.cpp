#include <iostream>
#include <cstdlib>
#include "Instance.hpp"
#include "Permutation.hpp"
#include "Neighbourhood.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <instance_file>" << std::endl;
        return EXIT_FAILURE;
    }

    Instance instance(argv[1]);
    std::cout << "size: " << instance.size() << std::endl
              << instance.matrix() << std::endl;

    return EXIT_SUCCESS;
}
