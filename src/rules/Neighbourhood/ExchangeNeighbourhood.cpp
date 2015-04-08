#include "ExchangeNeighbourhood.hpp"

ExchangeNeighbourhood::ExchangeNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void ExchangeNeighbourhood::start() {
    p_ = std::make_pair(0, 1);
}

bool ExchangeNeighbourhood::isValid() {
    return (covered_ <= size * (size_ - 1)/2);
}

void ExchangeNeighbourhood::next() {
    if (p_.second == size_ - 1) {
        p_.first++;
        p_.second = p_.first + 1;
    }
    else {
        p_second++;
    }
    
    covered_++;
}

Permutation ExchangeNeighbourhood::apply(Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(first(), second());
    return p2;
}
