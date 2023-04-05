#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat randomBureaucrat;
        randomBureaucrat.promote();
        randomBureaucrat.promote();
        std::cout << randomBureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat randomGoon;
        randomGoon.demote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat numberOne("Number one", 1);
        numberOne.promote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat numberOne("Number one", 1);
        numberOne.demote();
        numberOne.demote();
        std::cout << numberOne << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}