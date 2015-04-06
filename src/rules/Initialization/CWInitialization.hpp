#ifndef CW_INITIALIZATION
#define CW_INITIALIZATION

#include "Permutation.hpp"
#include "Instance.hpp"

class CWInitialization {
public:
    CWInitialization(Instance& instance);
    
    Permutation generateInitialization();
    
private:
    unsigned evaluateRows(const Permutation& permutation, unsigned step);
    long int evaluateRow(const Permutation& permutation, unsigned row,
        unsigned step);
    
    Instance& instance_;
};

#endif // CW_INITIALIZATION
