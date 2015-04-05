#include "FirstImprovement.hpp"

Permutation FirstImprovement::improve(const Instance& instance,
    const Permutation& p, Neighbourhood n)
{
    n.start();
    while(n.isValid()) {
        Permutation p2 = p;
        p2.permute(n.first(), n.second());

        long int scoreP = instance.evaluate(p);
        long int scoreP2 = instance.evaluate(p2);
        if (scoreP < scoreP2) {
            return p2;
        }
        
        n.next();
    }
    
    return p;
}
