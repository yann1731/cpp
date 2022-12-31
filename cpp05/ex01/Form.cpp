#include "Form.hpp"

//     void beSigned(const Bureaucrat &bureaucrat);
//     Form &operator=(const Form &src);
//     std::string getName(void) const;
//     bool getSignStatus(void) const;
//     int getGradeSign(void) const;
//     int getGradeExec(void) const;
// std::ostream &operator<<(const std::ostream &out, const Form &src);

Form::Form(): name("Random Form"), isSigned(false), gradeSign(1), gradeExec(1)
{
    std::cout << "Default form constructor called" << std::endl;
}

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    std::cout << "Custom form constructor called" << std::endl;
}

Form::Form(const Form &src): name(src.name), isSigned(false), gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
    std::cout << "Copy form constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Default form destructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
    *this = src;
    return *this;
}
