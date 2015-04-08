#ifndef TRANSPOSE_NEIGHBOURHOOD_HPP
#define TRANSPOSE_NEIGHBOURHOOD_HPP

#include "Neighbourhood.hpp"

class TransposeNeighbourhood : public Neighbourhood {
public:
    TransposeNeighbourhood(unsigned size);
    
    void start();
    bool isValid();
    void next();
    Permutation apply(Permutation& p1);
};

#endif // TRANSPOSE_NEIGHBOURHOOD_HPP
