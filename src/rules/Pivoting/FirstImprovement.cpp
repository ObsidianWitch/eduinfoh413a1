#include "FirstImprovement.hpp"

FirstImprovement::FirstImprovement(const Instance& instance) :
    Improvement(instance)
{}

Permutation FirstImprovement::improve(const Permutation& p, Neighbourhood& n) {
    long int scoreP = instance_.evaluate(p);
    
    n.start();
    while(n.isValid()) {
        Permutation p2 = n.apply(p);

        long int scoreP2 = instance_.evaluate(p, p2, scoreP, n);

        if (scoreP < scoreP2) {
            return p2;
        }
        
        n.next();
    }
    
    return p;
}
