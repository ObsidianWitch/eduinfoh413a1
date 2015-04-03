#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

class Neighbourhood {
public:
    virtual void start() = 0;
    virtual bool is_valid() = 0;
    virtual void next() = 0;

    operator unsigned() const { return i_; }

protected:
    unsigned i_;
};

#endif // NEIGHBOURHOOD_HPP
