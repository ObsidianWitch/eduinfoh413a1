#include <iostream>
#include <cstdlib>
#include <cassert>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/detail/matrix_assign.hpp>
#include <boost/numeric/ublas/io.hpp>
namespace ublas = boost::numeric::ublas;

#include "Instance.hpp"

int main() {
    ublas::matrix<int> testMatrix(5, 5);
    for (unsigned k = 0 ; k < 25 ; k++) {
        unsigned i = k / 5;
        unsigned j = k % 5;
        testMatrix(i,j) = k;
    }
    std::cout << "test matrix" << std::endl
              << testMatrix << std::endl << std::endl;
    
    Instance instance("../instances/test1");
    std::cout << "instance matrix" << std::endl
              << instance.matrix() << std::endl << std::endl;
    
    assert(ublas::detail::equals(testMatrix, instance.matrix(), 1.e-6, 0.));
    
    std::cout << "instance totalSum: " << instance.totalSum() << std::endl;
    assert(instance.totalSum() == 300);
    
    return EXIT_SUCCESS;
}
