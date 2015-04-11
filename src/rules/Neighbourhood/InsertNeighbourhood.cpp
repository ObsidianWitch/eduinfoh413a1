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
    p2.erase(p_.first);
    p2.insert(p_.second, p1[p_.first]);
    
    return p2;
}

long int InsertNeighbourhood::delta(const Matrix& matrix,
    const Permutation& oldP, const Permutation& newP) const
{
    long int deltaOldScore = 0;
    long int deltaNewScore = 0;
    long int first = p_.first;
    long int second = p_.second;
    
    for (unsigned i = 0 ; i < size_ ; i++) {
        for (unsigned j = i + 1 ; j < size_ ; j++) {
            bool inCommon = (i < first)
                || (i > second)
                || (j < first)
                || (j > second);

            if (!inCommon) {
                // compute modified zone's score in old permutation
                deltaOldScore += matrix[oldP[i]][oldP[j]];
                
                // compute modified zone's score in new permutation
                deltaNewScore += matrix[newP[i]][newP[j]];
            }
        }
    }
    
    return deltaNewScore - deltaOldScore;
}
