#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat randomBureaucrat;
        Bureaucrat marvin("Marvin the miserable", 34);
        Bureaucrat numberOne("Number one", 1);
        Bureaucrat b = marvin;
        std::cout << b << std::endl;
        b.promote();
        std::cout << b.getGrade() << std::endl;
        std::cout << marvin.getGrade() << std::endl;
        std::cout << marvin << std::endl;
        std::cout << randomBureaucrat << std::endl;
        std::cout << numberOne << std::endl;
        //numberOne.promote();
        randomBureaucrat.promote();
        std::cout << randomBureaucrat << std::endl;
        randomBureaucrat.demote();
        randomBureaucrat.demote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}