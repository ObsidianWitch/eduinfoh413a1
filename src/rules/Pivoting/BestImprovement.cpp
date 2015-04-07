#include "BestImprovement.hpp"

BestImprovement::BestImprovement(const Instance& instance) :
    Improvement(instance)
{}

Permutation BestImprovement::improve(const Permutation& p, Neighbourhood& n) {
    Permutation p1 = p;
    
    n.start();
    while(n.isValid()) {
        Permutation p2 = p;
        p2.permute(n.first(), n.second());

        long int scoreP1 = instance_.evaluate(p1);
        long int scoreP2 = instance_.evaluate(p2);
        if (scoreP1 < scoreP2) {
            p1 = p2;
        }
        
        n.next();
    }
    
    return p1;
}
