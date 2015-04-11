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

    for (unsigned i = 0 ; i < size_ ; i++) {
        for (unsigned j = i + 1 ; j < size_ ; j++) {
            bool iInPair = (i == first) || (i == second);
            bool jInPair = (j == first) || (j == second);
            
            bool inCommon = (!iInPair && !jInPair)
                || (i == first && !jInPair && j > second)
                || (i == second && !jInPair && j > first)
                || (j == first && !iInPair && i < second)
                || (j == second && !iInPair && i < first);

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
