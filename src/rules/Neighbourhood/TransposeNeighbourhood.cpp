#include "TransposeNeighbourhood.hpp"

TransposeNeighbourhood::TransposeNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void TransposeNeighbourhood::start() {
    p_ = std::make_pair(0, 1);
}

bool TransposeNeighbourhood::isValid() {
    return p_.first + 1 < size_;
}

void TransposeNeighbourhood::next() {
    p_.first++;
    p_.second = p_.first + 1;
}

Permutation TransposeNeighbourhood::apply(Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(first(), second());
    return p2;
}
