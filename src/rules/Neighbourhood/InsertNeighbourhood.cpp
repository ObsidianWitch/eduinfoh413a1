#include "InsertNeighbourhood.hpp"

InsertNeighbourhood::InsertNeighbourhood(unsigned size) :
    Neighbourhood(size)
{}

void InsertNeighbourhood::start() {
    p_ = std::make_pair(0, 1); // TODO
}

bool InsertNeighbourhood::isValid() {
    return (covered_ <= (size_ - 1) * (size_ - 1));
}

void InsertNeighbourhood::next() {
    if (p_second == size_) {
        p_.first++;
        p_.second = 0;
    }
    else {
        p_.second++;
    }
    
    if (p_.first == p_.second) {
        next();
        covered_--;
    }
    
    covered_++;
}

Permutation InsertNeighbourhood::apply(Permutation& p1) {
    Permutation p2 = p1;
    p2.remove(first())
    p2.insert(second() + 1, p1[first()]);
    
    return p2;
}
