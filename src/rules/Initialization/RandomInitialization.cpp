#include <functional>
#include "RandomInitialization.hpp"

RandomInitialization::RandomInitialization(long int seed, unsigned size) :
    randomEngine_(seed), size_(size)
{}

Permutation RandomInitialization::generateInitialization() {
    std::uniform_int_distribution<unsigned> distribution(0, size_ - 1);
    auto generator = std::bind(distribution, randomEngine_);
    Permutation randomPermutation(size_);
    
    for (unsigned i = 0 ; i < randomPermutation.size() ; i++) {
        unsigned randomIndex = generator();
        
        randomPermutation.permute(i, randomIndex);
    }
    
    return randomPermutation;
}
