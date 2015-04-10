#include "ExchangeNeighbourhood.hpp"

ExchangeNeighbourhood::ExchangeNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void ExchangeNeighbourhood::start() {
    p_ = std::make_pair(0, 1);
}

bool ExchangeNeighbourhood::isValid() {
    return p_.first < size_ - 1;
}

void ExchangeNeighbourhood::next() {
    if (p_.second == size_ - 1) {
        p_.first++;
        p_.second = p_.first + 1;
    }
    else {
        p_.second++;
    }
}

Permutation ExchangeNeighbourhood::apply(const Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(first(), second());
    return p2;
}

bool ExchangeNeighbourhood::inCommon(unsigned i, unsigned j) const {
    bool iInPair = (i == first()) || (i == second());
    bool jInPair = (j == first()) || (j == second());
    
    bool inCommon = (!iInPair && !jInPair)
        || (i == first() && !jInPair && j > second())
        || (i == second() && !jInPair && j > first())
        || (j == first() && !iInPair && i < second())
        || (j == second() && !iInPair && i < first());
    
    return inCommon;
}
