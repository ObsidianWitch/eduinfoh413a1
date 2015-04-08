#ifndef INSERT_NEIGHBOURHOOD_HPP
#define INSERT_NEIGHBOURHOOD_HPP

#include "Neighbourhood.hpp"

class InsertNeighbourhood : public Neighbourhood {
    InsertNeighbourhood(unsigned size);
    
    void start();
    bool isValid();
    void next();
    Permutation apply(Permutation& p1);
};

#endif // INSERT_NEIGHBOURHOOD_HPP
