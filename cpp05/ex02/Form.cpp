#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Random Form"), isSigned(false), gradeSign(1), gradeExec(1)
{
}

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign <= 0 || gradeExec <= 0)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src): name(src.name), isSigned(false), gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
    if (gradeSign <= 0 || gradeExec <= 0)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
}

void Form::execute(const Bureaucrat &executor)
{
    if (isSigned == false)
        throw Form::FormNotSigned();
    else if (executor.getGrade() > gradeExec)
        throw Form::GradeTooLowException();
    else
        execute(executor);
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
    if (src.getGrade() > gradeSign)
        throw GradeTooLowException();
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

const char *Form::FormNotSigned::what() const throw()
{
    return ("Exception: Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
    out << src.getName() << "\n" << src.getSignStatus() << "\n" << src.getGradeSign() << "\n" << \
    src.getGradeExec();
    return out;
}
