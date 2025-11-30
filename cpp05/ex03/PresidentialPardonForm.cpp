#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src), target(src.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    if (this != &src) {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}