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
    virtual void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor);
    virtual void order66(const Bureaucrat &executor) const = 0;
    virtual Form &operator=(const Form &src);
    std::string getName(void) const;
    bool getSignStatus(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;
    class GradeTooLowException: public std::exception
    {
    public:
        const char *what() throw();
    };
    class GradeTooHighException: public std::exception
    {
    public:
        const char *what() throw();
    };
    class FormNotSigned: public std::exception
    {
    public:
        const char *what() throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Form &src);

#endif