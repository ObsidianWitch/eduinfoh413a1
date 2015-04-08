#ifndef EXCHANGE_NEIGHBOURHOOD_HPP
#define EXCHANGE_NEIGHBOURHOOD_HPP

#include "Neighbourhood.hpp"

class ExchangeNeighbourhood : public Neighbourhood {
    ExchangeNeighbourhood(unsigned size);
    
    void start();
    bool isValid();
    void next();
    Permutation apply(Permutation& p1);
};

#endif // EXCHANGE_NEIGHBOURHOOD_HPP
