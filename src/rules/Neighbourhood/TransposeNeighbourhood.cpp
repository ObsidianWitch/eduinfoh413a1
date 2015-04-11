#include "TransposeNeighbourhood.hpp"

TransposeNeighbourhood::TransposeNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void TransposeNeighbourhood::start() {
    p_ = std::make_pair(0, 1);
}

bool TransposeNeighbourhood::isValid() {
    return p_.second < size_;
}

void TransposeNeighbourhood::next() {
    p_.first++;
    p_.second = p_.first + 1;
}

Permutation TransposeNeighbourhood::apply(const Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(p_.first, p_.second);
    return p2;
}

bool TransposeNeighbourhood::inCommon(unsigned i, unsigned j) const {
    bool iInPair = (i == p_.first) || (i == p_.second);
    bool jInPair = (j == p_.first) || (j == p_.second);
    
    bool inCommon = (!iInPair && !jInPair)
        || (i == p_.first && !jInPair && j > p_.second)
        || (i == p_.second && !jInPair && j > p_.first)
        || (j == p_.first && !iInPair && i < p_.second)
        || (j == p_.second && !iInPair && i < p_.first);
    
    return inCommon;
}
