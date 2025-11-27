#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), target(src.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    if (this != &src) {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cout << "Error: Could not create file" << std::endl;
        return;
    }
    
    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    file << "\n";
    file << "      #####\n";
    file << "     ##   ##\n";
    file << "    #  ^ ^  #\n";
    file << "   #  (o o)  #\n";
    file << "  #   ( > )   #\n";
    file << " #     ~~~     #\n";
    file << "       |||\n";
    file << "       |||\n";
    
    file.close();
    std::cout << "Shrubbery created at " << filename << std::endl;
}