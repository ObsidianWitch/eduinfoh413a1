#include "BestImprovement.hpp"

BestImprovement::BestImprovement(const Instance& instance, Neighbourhood n) :
    Improvement(instance, n)
{}

Permutation BestImprovement::improve(const Permutation& p) {
    Permutation p1 = p;
    
    n_.start();
    while(n_.isValid()) {
        Permutation p2 = p;
        p2.permute(n_.first(), n_.second());

        long int scoreP1 = instance_.evaluate(p1);
        long int scoreP2 = instance_.evaluate(p2);
        if (scoreP1 < scoreP2) {
            p1 = p2;
        }
        
        n_.next();
    }
    
    return p1;
}
