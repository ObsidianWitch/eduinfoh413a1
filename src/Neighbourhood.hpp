#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

class Neighbourhood {
public:
    static const unsigned TRANSPOSE = 1;
    static const unsigned EXCHANGE  = 2;
    static const unsigned INSERTION = 3;

    Neighbourhood(unsigned size, unsigned step) :
        i_(0), size_(size), step_(step)
    {}

    bool hasNext() { return i_ + step_ <= size_; }
    void next() { i_ += step_; }

    operator unsigned() const { return i_; }

protected:
    unsigned i_;
    unsigned size_;
    unsigned step_;
};

#endif // NEIGHBOURHOOD_HPP
