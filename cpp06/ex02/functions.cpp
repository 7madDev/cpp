#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int random = rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Error: NULL pointer" << std::endl;
        return;
    }
    
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
        return;
    }
    
    if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
        return;
    }
    
    if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
        return;
    }
    
    std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {
    }
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {
    }
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {
    }
    
    std::cout << "Unknown type" << std::endl;
}