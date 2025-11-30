#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        
        // Test Shrubbery
        ShrubberyCreationForm shrub("home");
        boss.signForm(shrub);
        boss.executeForm(shrub);
        
        std::cout << "\n";
        
        // Test Robotomy
        RobotomyRequestForm robot("Bender");
        boss.signForm(robot);
        boss.executeForm(robot);
        
        std::cout << "\n";
        
        // Test Presidential Pardon
        PresidentialPardonForm pardon("pause flow");
        boss.signForm(pardon);
        boss.executeForm(pardon);
        
        std::cout << "\n";
        
        // Test with low-grade bureaucrat
        ShrubberyCreationForm shrub2("garden");
        intern.signForm(shrub2);
        intern.executeForm(shrub2);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}