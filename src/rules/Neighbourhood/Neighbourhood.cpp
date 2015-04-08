#include "Neighbourhood.hpp"

Neighbourhood::Neighbourhood(unsigned size) : size_(size), covered_(1) {}

Neighbourhood::operator Point() const {
    return p_;
}

unsigned Neighbourhood::first() {
    return p_.first;
}

unsigned Neighbourhood::second() {
    return p_.second;
}

std::ostream& operator<<(std::ostream& ostr, const Point& p) {
    ostr << "(" << p.first << "," << p.second << ")";

    return ostr;
}
