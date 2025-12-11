#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::cout << "=== std::vector ===" << std::endl;
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);
        
        try {
            std::vector<int>::iterator it = easyfind(vec, 30);
            std::cout << "Found: " << *it << std::endl;
            std::cout << "Position: " << (it - vec.begin()) << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::vector<int>::iterator it = easyfind(vec, 99);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== std::list ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(10);
        lst.push_back(15);
        lst.push_back(20);
        
        try {
            std::list<int>::iterator it = easyfind(lst, 15);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        try {
            std::list<int>::iterator it = easyfind(lst, 100);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== std::deque ===" << std::endl;
    {
        std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        
        try {
            std::deque<int>::iterator it = easyfind(deq, 2);
            std::cout << "Found: " << *it << std::endl;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== Empty container ===" << std::endl;
    {
        std::vector<int> empty;
        
        try {
            easyfind(empty, 42);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    return 0;
}