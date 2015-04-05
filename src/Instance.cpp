#include <fstream>
#include "Instance.hpp"

Instance::Instance(std::string filePath) :
    filePath_(filePath), totalSum_(0)
{
    parseToMatrix();
}

// TODO handle badly formatted files
void Instance::parseToMatrix() {
    std::ifstream ifs(filePath_.c_str());
    std::stringstream ss;
    ss << ifs.rdbuf();
    
    // instance size
    ss >> size_;
    
    // Matrix
    matrix_ = ublas::matrix<int>(size_, size_);
    for (unsigned i = 0 ; i < matrix_.size1() ; i++) {
        for (unsigned j = 0 ; j < matrix_.size2() ; j++) {
            ss >> matrix_(i,j);
            totalSum_ += matrix_(i,j);
        }
    }
}

std::string Instance::toStringMatrixPermutation(const Permutation& p) {
    std::ostringstream os;
    unsigned size = p.size();
    
    os << "[" << size << "," << size << "]" << "(";
    
    for (unsigned i = 0 ; i < size ; i++) {
        os << "(";
        
        for (unsigned j = 0 ; j < size ; j++) {
            os << matrix_(p[i], p[j]);
            
            if (j < size - 1) {
                os << ",";
            }
        }
        
        os << ")";
        
        if (i < size - 1) {
            os << ",";
        }
    }
    
    os << ")";
    
    return os.str();
}

unsigned Instance::size() const { return size_; }
ublas::matrix<int> Instance::matrix() const { return matrix_; }
long int Instance::totalSum() const { return totalSum_; }
