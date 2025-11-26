#include "Bureaucrat.hpp"

int main() {
    std::cout << "===== valid signing =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 40);
        Form formA("FormA", 50, 25);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);

        std::cout << formA << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== sign fail (grade too low) =====" << std::endl;
    try {
        Bureaucrat john("John", 100);
        Form formB("FormB", 50, 25);

        john.signForm(formB);
        std::cout << formB << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== invalid form =====" << std::endl;
    try {
        Form badForm("BadForm", 0, 160);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
