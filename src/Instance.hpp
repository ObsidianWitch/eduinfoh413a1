#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <string>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
namespace ublas = boost::numeric::ublas;

class Instance {
public:
    Instance(std::string filePath);
    
    void parseToMatrix();
    
    unsigned size();
    ublas::matrix<int> matrix();
    
private:
    std::string filePath_;
    unsigned size_;
    ublas::matrix<int> matrix_;
};

#endif // INSTANCE_HPP
