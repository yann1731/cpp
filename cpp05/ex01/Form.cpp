#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Random Form"), isSigned(false), gradeSign(1), gradeExec(1)
{
    std::cout << "Default form constructor called" << std::endl;
}

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    std::cout << "Custom form constructor called" << std::endl;
    if (gradeSign <= 0 || gradeExec <= 0)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src): name(src.name), isSigned(false), gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
    std::cout << "Copy form constructor called" << std::endl;
    if (gradeSign <= 0 || gradeExec <= 0)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Default form destructor called" << std::endl;
}

std::string Form::getName(void) const
{
    return name;
}

bool Form::getSignStatus(void) const
{
    return isSigned;
}

int Form::getGradeSign(void) const
{
    return gradeSign;
}

int Form::getGradeExec(void) const
{
    return gradeExec;
}

void Form::beSigned(const Bureaucrat &src)
{
    if (isSigned == true)
    {
        std::cout << "Wtf this is already signed" << std::endl;
        return ;
    }
    else if (src.getGrade() > gradeSign || src.getGrade() > gradeExec)
    {
        std::cout << "You're too noob to sign this. Get out plz" << std::endl;
        return ;
    }
    else
    isSigned = true;
}

Form &Form::operator=(const Form &src)
{
    this->isSigned = src.getSignStatus();
    return *this;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade too high!");
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
    out << src.getName() << "\n" << src.getSignStatus() << "\n" << src.getGradeSign() << "\n" << src.getGradeExec();
    return out;
}
