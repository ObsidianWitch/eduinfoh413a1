#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP

#include <vector>
#include <iostream>

class Permutation {
public:
    Permutation(unsigned size);

    void fill();
    void permute(unsigned i1, unsigned i2);

    // Operators
    unsigned operator[](unsigned i) const;
    unsigned& operator[](unsigned i);

    // Accessors
    unsigned size() const;
    void resize(unsigned size);
    
private:
    std::vector<unsigned> indices_;
    unsigned size_;
};

std::ostream& operator<<(std::ostream& ostr, const Permutation& perm);

#endif // PERMUTATION_HPP
