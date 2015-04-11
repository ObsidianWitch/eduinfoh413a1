#include "Neighbourhood.hpp"

Neighbourhood::Neighbourhood(unsigned size) : size_(size) {}

Neighbourhood::operator Pair() const {
    return p_;
}

unsigned Neighbourhood::first() const {
    return p_.first;
}

unsigned Neighbourhood::second() const {
    return p_.second;
}

std::ostream& operator<<(std::ostream& ostr, const Pair& p) {
    ostr << "(" << p.first << "," << p.second << ")";

    return ostr;
}

long int Neighbourhood::delta(const Matrix& matrix, const Permutation& oldP,
    const Permutation& newP) const
{
    long int deltaOldScore = 0;
    long int deltaNewScore = 0;
    long int first = p_.first;
    long int second = p_.second;

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
