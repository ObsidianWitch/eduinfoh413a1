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
    p2.permute(p_.first, p_.second);
    return p2;
}

bool ExchangeNeighbourhood::inCommon(unsigned i, unsigned j) const {
    bool iInPair = (i == p_.first) || (i == p_.second);
    bool jInPair = (j == p_.first) || (j == p_.second);
    
    bool inCommon = (!iInPair && !jInPair)
        || (i == p_.first && !jInPair && j > p_.second)
        || (i == p_.second && !jInPair && j > p_.first)
        || (j == p_.first && !iInPair && i < p_.second)
        || (j == p_.second && !iInPair && i < p_.first);
    
    return inCommon;
}
