#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void increment(T& x) {
    x++;
}

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

void doubleIt(int& x) {
    x *= 2;
}

void toUpper(char& c) {
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

int main() {
    std::cout << "=== Int array ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;
    
    std::cout << "Original: ";
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl;
    
    std::cout << "After increment: ";
    ::iter(intArray, intLen, increment<int>);
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl;
    
    std::cout << "After double: ";
    ::iter(intArray, intLen, doubleIt);
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl;
    
    std::cout << "\n=== String array ===" << std::endl;
    std::string strArray[] = {"hello", "world", "foo", "bar"};
    size_t strLen = 4;
    
    std::cout << "Strings: ";
    ::iter(strArray, strLen, print<std::string>);
    std::cout << std::endl;
    
    std::cout << "\n=== Char array ===" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charLen = 5;
    
    std::cout << "Original: ";
    ::iter(charArray, charLen, print<char>);
    std::cout << std::endl;
    
    std::cout << "After toUpper: ";
    ::iter(charArray, charLen, toUpper);
    ::iter(charArray, charLen, print<char>);
    std::cout << std::endl;
    
    std::cout << "\n=== Double array ===" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleLen = 4;
    
    std::cout << "Doubles: ";
    ::iter(doubleArray, doubleLen, print<double>);
    std::cout << std::endl;
    
    return 0;
}