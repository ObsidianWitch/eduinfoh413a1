#include "FirstImprovement.hpp"

FirstImprovement::FirstImprovement(const Instance& instance, Neighbourhood n) :
    Improvement(instance, n)
{}

Permutation FirstImprovement::improve(const Permutation& p) {
    n_.start();
    while(n_.isValid()) {
        Permutation p2 = p;
        p2.permute(n_.first(), n_.second());

        long int scoreP = instance_.evaluate(p);
        long int scoreP2 = instance_.evaluate(p2);
        
        if (scoreP < scoreP2) {
            // FIXME DEBUG std::cout << scoreP << " -> " << scoreP2 << std::endl;

            return p2;
        }
        
        n_.next();
    }
    
    return p;
}
