#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <string>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
namespace ublas = boost::numeric::ublas;

#include "Permutation.hpp"

class Instance {
public:
    Instance(std::string filePath);
    
    void parseToMatrix();
    
    std::string toStringMatrixPermutation(const Permutation& p);
    
    unsigned size() const;
    ublas::matrix<int> matrix() const;
    long int totalSum() const;

private:
    std::string filePath_;
    unsigned size_;
    ublas::matrix<int> matrix_;
    int totalSum_;
};

#endif // INSTANCE_HPP
