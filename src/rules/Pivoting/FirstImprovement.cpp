#include "FirstImprovement.hpp"

FirstImprovement::FirstImprovement(const Instance& instance) :
    Improvement(instance)
{}

Permutation FirstImprovement::improve(Permutation& p, Neighbourhood& n) {
    if (p.score() == -1) {
        long int scoreP = instance_.evaluate(p);
        p.setScore(scoreP);
    }
    
    n.start();
    while(n.isValid()) {
        Permutation p2 = n.apply(p);

        instance_.evaluate(p, p2, n);

        if (p.score() < p2.score()) {
            return p2;
        }
        
        n.next();
    }
    
    return p;
}
