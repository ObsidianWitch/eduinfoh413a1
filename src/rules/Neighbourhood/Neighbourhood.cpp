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
        if (first > k) {
            deltaOldScore += matrix[oldP[k]][oldP[first]];
            deltaNewScore += matrix[newP[k]][newP[first]];
        }
        
        if (second > k) {
            deltaOldScore += matrix[oldP[k]][oldP[second]];
            deltaNewScore += matrix[newP[k]][newP[second]];
        }
        
        if (first < k) {
            if (k != first && k != second) {
                deltaOldScore += matrix[oldP[first]][oldP[k]];
                deltaNewScore += matrix[newP[first]][newP[k]];
            }
        }
        
        if (second < k) {
            if (k != first && k != second) {
                deltaOldScore += matrix[oldP[second]][oldP[k]];
                deltaNewScore += matrix[newP[second]][newP[k]];
            }
        }
    }
    
    return deltaNewScore - deltaOldScore;
}
