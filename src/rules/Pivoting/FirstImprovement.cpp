#include "FirstImprovement.hpp"

FirstImprovement::FirstImprovement(const Instance& instance) :
    Improvement(instance)
{}

Permutation FirstImprovement::improve(const Permutation& p, Neighbourhood& n) {
    n.start();
    while(n.isValid()) {
        Permutation p2 = p;
        p2.permute(n.first(), n.second());

        long int scoreP = instance_.evaluate(p);
        long int scoreP2 = instance_.evaluate(p2);
        
        if (scoreP < scoreP2) {
            // FIXME DEBUG std::cout << scoreP << " -> " << scoreP2 << std::endl;

            return p2;
        }
        
        n.next();
    }
    
    return p;
}
