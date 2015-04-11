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

Permutation ExchangeNeighbourhood::apply(const Permutation& p1) {
    Permutation p2 = p1;
    p2.permute(p_.first, p_.second);
    return p2;
}

long int ExchangeNeighbourhood::delta(const Matrix& matrix,
    const Permutation& oldP, const Permutation& newP) const
{
    long int deltaOldScore = 0;
    long int deltaNewScore = 0;
    unsigned first = p_.first;
    unsigned second = p_.second;
    
    for (unsigned k = 0 ; k < size_ ; k++) {
        unsigned oldPk = oldP[k],
                 newPk = newP[k];
        unsigned oldPfirst = oldP[first],
                 newPfirst = newP[first];
        unsigned oldPsecond = oldP[second],
                 newPsecond = newP[second];
        
        if (first > k) {
            deltaOldScore += matrix[oldPk][oldPfirst];
            deltaNewScore += matrix[newPk][newPfirst];
        }
        
        if (second > k) {
            deltaOldScore += matrix[oldPk][oldPsecond];
            deltaNewScore += matrix[newPk][newPsecond];
        }
        
        if (first < k) {
            if (k != first && k != second) {
                deltaOldScore += matrix[oldPfirst][oldPk];
                deltaNewScore += matrix[newPfirst][newPk];
            }
        }
        
        if (second < k) {
            if (k != first && k != second) {
                deltaOldScore += matrix[oldPsecond][oldPk];
                deltaNewScore += matrix[newPsecond][newPk];
            }
        }
    }
    
    return deltaNewScore - deltaOldScore;
}
