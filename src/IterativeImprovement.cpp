#include "IterativeImprovement.hpp"

IterativeImprovement::IterativeImprovement(Instance& instance,
    Initialization& initialization, Improvement& improvement) :
    instance_(instance), initialization_(initialization),
    improvement_(improvement)
{}

void IterativeImprovement::run() {
    Permutation p(instance_.size());
    std::cout << "instance size: " << instance_.size() << std::endl
              << "instance score: " << instance_.evaluate(p) << std::endl
              << "seed: " << instance_.totalSum() << std::endl;

    bool localOptimum = false;
    Permutation p1 = initialization_.generateInitialization();
    std::cout << "initial solution (score: " << instance_.evaluate(p1) << "): "
              << p1 << std::endl;
    
    while (!localOptimum) {
        Permutation p2 = improvement_.improve(p1);
        
        localOptimum = (p1 == p2);
        p1 = p2;
    }
    std::cout << "final solution (score: " << instance_.evaluate(p1) << "): "
              << p1 << std::endl;
              
    std::cout << "best known score: " << instance_.bestScore() << std::endl;
}
