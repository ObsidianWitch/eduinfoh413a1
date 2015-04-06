#include "Permutation.hpp"

Permutation::Permutation(unsigned size) {
    resize(size);
    fill();
}

void Permutation::fill() {
    for (unsigned i = 0 ; i < size() ; i++) {
        indices_[i] = i;
    }
}

void Permutation::permute(unsigned i1, unsigned i2) {
    unsigned tmp = indices_[i1];

    indices_[i1] = indices_[i2];
    indices_[i2] = tmp;
}

unsigned Permutation::operator[](unsigned i) const {
    return indices_[i];
}

unsigned& Permutation::operator[](unsigned i) {
    return indices_[i];
}

bool Permutation::operator ==(const Permutation& b) const {
    for (unsigned i = 0 ; i < size() ; i++) {
        if (indices_[i] != b[i]) {
            return false;
        }
    }
    
    return true;
}

unsigned Permutation::size() const {
    return size_;
}

void Permutation::resize(unsigned size) {
    size_ = size;
    indices_.resize(size_);
}

std::ostream& operator<<(std::ostream& ostr, const Permutation& perm) {
    ostr << "(";

    for (unsigned i = 0 ; i < perm.size() ; i++) {
        if (i == perm.size() - 1) {
            ostr << perm[i];
        } else {
            ostr << perm[i] << ", ";
        }
    }

    ostr << ")" << std::endl;

    return ostr;
}
