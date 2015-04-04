#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Neighbourhood.hpp"

void testPrint() {
    Neighbourhood n(5, Neighbourhood::TRANSPOSE);
    while (n.hasNext()) {
        std::cout << n << std::endl;
        n.next();
    }
    std::cout << std::endl;
}

void testTranspose() {
    Neighbourhood n(5, Neighbourhood::TRANSPOSE);
    assert(n.first() == 0 && n.second() == 1);
    n.next();
    assert(n.first() == 1 && n.second() == 2);
    n.next();
    assert(n.first() == 2 && n.second() == 3);
    n.next();
    assert(n.first() == 3 && n.second() == 4);
    n.next();
    assert(!n.hasNext());
}

void testExchange() {
    Neighbourhood n(5, Neighbourhood::EXCHANGE);
    assert(n.first() == 0 && n.second() == 2);
    n.next();
    assert(n.first() == 1 && n.second() == 3);
    n.next();
    assert(n.first() == 2 && n.second() == 4);
    n.next();
    assert(!n.hasNext());
}

void testInsertion() {
    Neighbourhood n(5, Neighbourhood::INSERTION);
    assert(n.first() == 0 && n.second() == 3);
    n.next();
    assert(n.first() == 1 && n.second() == 4);
    n.next();
    assert(!n.hasNext());
}

int main() {
    testPrint();
    testTranspose();
    testExchange();
    testInsertion();
    
    return EXIT_SUCCESS;
}
