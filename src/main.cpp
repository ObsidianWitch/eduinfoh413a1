#include <iostream>
#include <cstdlib>
#include "Instance.hpp"
#include "Permutation.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <instance_file>" << std::endl;
        return EXIT_FAILURE;
    }

    Instance instance(argv[1]);
    std::cout << "size: " << instance.size() << std::endl
              << instance.matrix() << std::endl;

    // Test permutation
    Permutation p(10);
    std::cout << p;
    p.permute(0, 2);
    std::cout << p;

    return EXIT_SUCCESS;
}
