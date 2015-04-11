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

long int TransposeNeighbourhood::delta(const Matrix& matrix,
    const Permutation& oldP, const Permutation&) const
{
    unsigned first = p_.first;
    unsigned oldPfirst = oldP[first];
    
    long int delta = 0;
    for (unsigned k = first + 1 ; k <= p_.second ; k++) {
        delta += matrix[oldP[k]][oldPfirst] - matrix[oldPfirst][oldP[k]];
    }
    
    return delta;
}
