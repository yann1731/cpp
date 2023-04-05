#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat random;
        Form form("Robotomy form", 30, 30);
        random.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat chadMarvin("Marvin the miserable", 15);
        Form form("Robotomy form", 30, 30);
        chadMarvin.signForm(form);
        chadMarvin.signForm(form);
        std::cout << form.getSignStatus() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat numberOne("Number one", 1);
        Bureaucrat b("zZzZzZzZ", 10);

        b = numberOne;

        Form form("Shrubbery form", 40, 30);
        Form form2 = form;

        numberOne.signForm(form);
        std::cout << form << std::endl;
        std::cout << form2 << std::endl;

        std::cout << numberOne << std::endl;
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat numberOne("Number one", 1);
        Bureaucrat b("zZzZzZzZ", 10);

        b = numberOne;

        Form form("Shrubbery form", 40, 30);
        Form form2 = form;

        numberOne.signForm(form);
        std::cout << form << std::endl;
        std::cout << form2 << std::endl;

        std::cout << numberOne << std::endl;
        std::cout << b << std::endl;

        b.demote();
        b.promote();
        b.promote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}