#include "BestImprovement.hpp"

BestImprovement::BestImprovement(const Instance& instance) :
    Improvement(instance)
{}

Permutation BestImprovement::improve(const Permutation& p, Neighbourhood& n) {
    Permutation p1 = p;
    long int scoreP1 = instance_.evaluate(p1);
    
    n.start();
    while(n.isValid()) {
        Permutation p2 = n.apply(p);

        long int scoreP2 = instance_.evaluate(p2);
        
        if (scoreP1 < scoreP2) {
            p1 = p2;
            scoreP1 = scoreP2;
        }
        
        n.next();
    }
    
    return p1;
}
