#include "TransposeNeighbourhood.hpp"

TransposeNeighbourhood::TransposeNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void TransposeNeighbourhood::start() {
    p_ = std::make_pair(0, 1);
}

bool TransposeNeighbourhood::isValid() {
    return (covered_ <= (size_ - 1));
}

void TransposeNeighbourhood::next() {
    p_.first++;
    p_.second = p_.first + 1;
    
    covered_++;
}

Permutation TransposeNeighbourhood::apply(Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(first(), second());
    return p2;
}
