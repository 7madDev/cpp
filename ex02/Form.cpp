#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec)
    : name(name), isSigned(false),
      gradeToSign(gradeSign), gradeToExecute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other){
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << f.getName() << ", form sign grade " << f.getGradeToSign()
        << ", exec grade " << f.getGradeToExecute()
        << ", signed: " << (f.getIsSigned() ? "true" : "false");
    return out;
}
