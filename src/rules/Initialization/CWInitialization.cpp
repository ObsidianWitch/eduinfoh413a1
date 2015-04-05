#include "CWInitialization.hpp"

CWInitialization::CWInitialization(const Instance& instance) :
    instance_(instance)
{}

Permutation CWInitialization::generateInitialization() {
    unsigned size = instance_.size();
    
    Permutation permutation(size);
    
    for (unsigned step = 0 ; step < size ; step++) {
        unsigned bestRow = evaluateRows(permutation, step);
        
        // TODO is that really what we want?
        // "Construct the solution by inserting one row at a time"
        // But here we permute the rows AND the columns
        permutation.permute(step, bestRow);
    }
    
    return permutation;
}

/**
 * Pick the best row at the specified step.
 */
unsigned CWInitialization::evaluateRows(const Permutation& permutation, unsigned step) {
    unsigned bestRow = step;
    long int bestRowScore = -1;
    
    for (unsigned row = step ; row < instance_.size() ; row++) {
        long int currentRowScore = evaluateRow(permutation, row, step);
        
        if (bestRowScore < currentRowScore) {
            bestRow = row;
            bestRowScore = currentRowScore;
        }
    }
    
    return bestRow;
}

long int CWInitialization::evaluateRow(const Permutation& permutation, unsigned row,
    unsigned step)
{
    const ublas::matrix<int> &matrix = instance_.matrix();
    long int score = 0;
    
    for (unsigned col = 1 + step ; col < instance_.size() ; col++) {
        score += matrix(permutation[row], col);
    }
    
    return score;
}
