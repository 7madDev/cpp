#include "functions.hpp"
#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Generate and Identify (Pointer) ===" << std::endl;
    
    Base* obj1 = generate();
    std::cout << "identify(Base* p): ";
    identify(obj1);
    
    std::cout << "\n=== Test 2: Generate and Identify (Reference) ===" << std::endl;
    
    Base* obj2 = generate();
    std::cout << "identify(Base& p): ";
    identify(*obj2);
    
    std::cout << "\n=== Test 3: Multiple Random Objects ===" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        std::cout << "Pointer version: ";
        identify(obj);
        std::cout << "Reference version: ";
        identify(*obj);
        std::cout << std::endl;
        delete obj;
    }
    
    delete obj1;
    delete obj2;
    
    return 0;
}