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
    p2.permute(first(), second());
    return p2;
}

bool TransposeNeighbourhood::inCommon(unsigned i, unsigned j) const {
    bool iInPair = (i == first()) || (i == second());
    bool jInPair = (j == first()) || (j == second());
    
    bool inCommon = (!iInPair && !jInPair)
        || (i == first() && !jInPair && j > second())
        || (i == second() && !jInPair && j > first())
        || (j == first() && !iInPair && i < second())
        || (j == second() && !iInPair && i < first());
    
    return inCommon;
}
