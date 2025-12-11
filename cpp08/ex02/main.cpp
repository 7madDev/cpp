#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "=== Subject Test ===" << std::endl;
    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Exception Tests ===" << std::endl;
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        
        try {
            sp.addNumber(4);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        Span sp2(1);
        sp2.addNumber(42);
        
        try {
            sp2.shortestSpan();
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
    {
        Span sp(10000);
        
        srand(time(NULL));
        for (int i = 0; i < 10000; i++) {
            sp.addNumber(rand());
        }
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Range Addition Test ===" << std::endl;
    {
        Span sp(10);
        
        std::vector<int> vec;
        for (int i = 0; i < 10; i++) {
            vec.push_back(i * 10);
        }
        
        sp.addRange(vec.begin(), vec.end());
        
        std::cout << "Added " << vec.size() << " numbers using range" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Negative Numbers Test ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    return 0;
}