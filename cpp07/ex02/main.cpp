#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty size: " << empty.getSize() << std::endl;

    std::cout << "\n=== array with values ===" << std::endl;
    Array<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    std::cout << "a: ";
    for (size_t i = 0; i < a.getSize(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== copy constructor ===" << std::endl;
    Array<int> b(a);
    b[0] = 99;

    std::cout << "a[0]: " << a[0] << std::endl;
    std::cout << "b[0]: " << b[0] << std::endl;

    std::cout << "\n=== assignment operator ===" << std::endl;
    Array<int> c(5);
    c = a;

    std::cout << "c: ";
    for (size_t i = 0; i < c.getSize(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== out of bounds ===" << std::endl;
    try {
        std::cout << a[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== different type (std::string) ===" << std::endl;
    Array<std::string> strs(2);
    strs[0] = "Hello";
    strs[1] = "42";

    for (size_t i = 0; i < strs.getSize(); i++)
        std::cout << strs[i] << " ";
    std::cout << std::endl;

    return 0;
}
