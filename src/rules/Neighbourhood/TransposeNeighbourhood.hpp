#ifndef TRANSPOSE_NEIGHBOURHOOD_HPP
#define TRANSPOSE_NEIGHBOURHOOD_HPP

#include "Neighbourhood.hpp"

class TransposeNeighbourhood : public Neighbourhood {
public:
    TransposeNeighbourhood(unsigned size);
    
    void start();
    bool isValid();
    void next();
    Permutation apply(const Permutation& p1);
    bool inCommon(unsigned i, unsigned j) const;
};

#endif // TRANSPOSE_NEIGHBOURHOOD_HPP
