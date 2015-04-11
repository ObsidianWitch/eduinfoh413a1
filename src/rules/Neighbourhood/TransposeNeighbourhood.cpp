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
