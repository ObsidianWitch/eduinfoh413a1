#include "BestImprovement.hpp"

BestImprovement::BestImprovement(const Instance& instance) :
    Improvement(instance)
{}

Permutation BestImprovement::improve(Permutation& p, Neighbourhood& n) {
    if (p.score() == -1) {
        instance_.evaluate(p);
    }
    
    Permutation p1 = p;
    
    n.start();
    while(n.isValid()) {
        Permutation p2 = n.apply(p);

        instance_.evaluate(p1, p2, n);
        
        if (p1.score() < p2.score()) {
            p1 = p2;
        }
        
        n.next();
    }
    
    return p1;
}
