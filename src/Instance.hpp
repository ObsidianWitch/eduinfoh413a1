#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <string>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
namespace ublas = boost::numeric::ublas;

#include "Permutation.hpp"

class Instance {
public:
    Instance(std::string filePath);
    
    void parseToMatrix();
    long int evaluate(const Permutation& p) const;
    void permuteRows(const Permutation& p);
    std::string toStringMatrixPermutation(const Permutation& p) const;
    
    int operator()(unsigned i, unsigned j) const;
    int& operator()(unsigned i, unsigned j);
    friend std::ostream& operator<<(std::ostream& ostr,
        const Instance& instance);
    
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
