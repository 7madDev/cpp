#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Valid Bureaucrat ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Too High ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Too Low ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Increment Beyond Limit ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}