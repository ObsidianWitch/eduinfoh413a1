#ifndef ITERATIVE_IMPROVEMENT_HPP
#define ITERATIVE_IMPROVEMENT_HPP

#include "rules/Initialization/Initialization.hpp"
#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/Improvement.hpp"

class IterativeImprovement {
public:
    IterativeImprovement(Instance& instance_, Initialization& initialization,
        Improvement& improvement);
    
    void run();

private:
    Instance& instance_;
    Initialization& initialization_;
    Improvement& improvement_;
};

#endif // ITERATIVE_IMPROVEMENT_HPP
