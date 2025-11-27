#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);
    
    std::cout << "=== Valid Forms ===" << std::endl;
    
    AForm* form1 = intern.makeForm("shrubbery creation", "home");
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    std::cout << "\n";
    
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    
    std::cout << "\n";
    
    AForm* form3 = intern.makeForm("presidential pardon", "Arthur");
    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }
    
    std::cout << "\n=== Invalid Form ===" << std::endl;
    AForm* invalid = intern.makeForm("invalid form", "target");
    if (!invalid) {
        std::cout << "Form creation failed as expected" << std::endl;
    }
    
    return 0;
}