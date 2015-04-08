#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include <utility>
#include <iostream>
#include "Permutation.hpp"

typedef std::pair<unsigned, unsigned> Pair;

class Neighbourhood {
public:
    Neighbourhood(unsigned size);
    virtual ~Neighbourhood() {}
    
    virtual void start() = 0;
    virtual bool isValid() = 0;
    virtual void next() = 0;
    virtual Permutation apply(const Permutation& p1) = 0;

    operator Pair() const;
    
    unsigned first();
    unsigned second();

protected:
    Pair p_;
    unsigned size_;
};

std::ostream& operator<<(std::ostream& ostr, const Pair& p);

#endif // NEIGHBOURHOOD_HPP
