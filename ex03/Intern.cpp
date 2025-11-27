#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    struct FormType {
        std::string name;
        AForm* (*create)(std::string);
    };
    
    FormType forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
    };
    
    for (int i = 0; i < 3; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    
    std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
    return NULL;
}