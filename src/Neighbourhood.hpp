#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include <utility>

typedef std::pair<unsigned, unsigned> Point;

std::ostream& operator<<(std::ostream& ostr, const Point& p) {
    ostr << "(" << p.first << "," << p.second << ")";

    return ostr;
}

class Neighbourhood {
public:
    static const unsigned TRANSPOSE = 1;
    static const unsigned EXCHANGE  = 2;
    static const unsigned INSERTION = 3;

    Neighbourhood(unsigned size, unsigned step) :
        p_(0,step), size_(size), step_(step)
    {}

    bool hasNext() { return p_.first + step_ < size_; }
    void next() {
        p_.first++;
        p_.second = p_.first + step_;
    }

    operator Point() const { return p_; }

protected:
    Point p_;
    unsigned size_;
    unsigned step_;
};

#endif // NEIGHBOURHOOD_HPP
