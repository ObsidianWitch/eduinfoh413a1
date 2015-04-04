#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include <utility>
#include <iostream>

typedef std::pair<unsigned, unsigned> Point;

class Neighbourhood {
public:
    static const unsigned TRANSPOSE = 1;
    static const unsigned EXCHANGE  = 2;
    static const unsigned INSERTION = 3;

    Neighbourhood(unsigned size, unsigned step);

    bool hasNext();
    void next();

    operator Point() const;

protected:
    Point p_;
    unsigned size_;
    unsigned step_;
};

std::ostream& operator<<(std::ostream& ostr, const Point& p);

#endif // NEIGHBOURHOOD_HPP
