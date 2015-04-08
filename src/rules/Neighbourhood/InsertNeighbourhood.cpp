#include "InsertNeighbourhood.hpp"

InsertNeighbourhood::InsertNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void InsertNeighbourhood::start() {
    p_ = std::make_pair(0, 1);
}

bool InsertNeighbourhood::isValid() {
    return p_.first < size_;
}

void InsertNeighbourhood::next() {
    // progress
    if (p_.second == size_ - 1) {
        p_.first++;
        p_.second = 0;
    }
    else {
        p_.second++;
    }
    
    // skip duplicates
    if ((p_.first == p_.second) || (p_.first == p_.second + 1)) {
        next();
    }
}

Permutation InsertNeighbourhood::apply(const Permutation& p1) {
    Permutation p2 = p1;
    p2.erase(first());
    p2.insert(second(), p1[first()]);
    
    return p2;
}
