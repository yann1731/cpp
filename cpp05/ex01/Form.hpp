#ifndef FORM_HPP
#define FORM_HPP
# include <iostream>
class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeSign;
    const int gradeExec;
    Form();
public:
    Form(const std::string &name, const int &gradeSign, const int &gradeExec);
    Form(const Form &src);
    ~Form();
    void beSigned(const Bureaucrat &bureaucrat);
    Form &operator=(const Form &src);
    std::string getName(void) const;
    bool getSignStatus(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;
    class GradeTooLowException: public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooHighException: public std::exception
    {
        const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Form &src);

#endif