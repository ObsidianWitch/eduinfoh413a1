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

    // Test permutation
    Permutation p(10);
    std::cout << p;
    p.permute(0, 2);
    std::cout << p;

    // Test neighbourhoods
    Neighbourhood n1(5, Neighbourhood::TRANSPOSE);
    while (n1.hasNext()) {
        std::cout << n1 << std::endl;
        n1.next();
    }
    std::cout << std::endl;

    Neighbourhood n2(5, Neighbourhood::EXCHANGE);
    while (n2.hasNext()) {
        std::cout << n2 << std::endl;
        n2.next();
    }
    std::cout << std::endl;

    Neighbourhood n3(5, Neighbourhood::INSERTION);
    while (n3.hasNext()) {
        std::cout << n3 << std::endl;
        n3.next();
    }

    return EXIT_SUCCESS;
}
