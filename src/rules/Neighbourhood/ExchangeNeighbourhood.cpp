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

Permutation ExchangeNeighbourhood::apply(Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(first(), second());
    return p2;
}
