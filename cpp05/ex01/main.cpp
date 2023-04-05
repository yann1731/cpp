#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
int main(void)
{
    try
    {
        Bureaucrat randomBureaucrat;
        Bureaucrat marvin("Marvin the miserable", 34);
        Bureaucrat numberOne("Number one", 1);
        Bureaucrat b = marvin;
        Form form("Robotomy form", 30, 30);
        Form form2 = form;

        cout << form2 << endl;
        cout << b << endl;
        try
        {
            b.promote(); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        cout << b.getGrade() << endl;
        cout << marvin.getGrade() << endl;
        cout << marvin << endl;
        cout << randomBureaucrat << endl;
        cout << numberOne << endl;
        try
        {
            numberOne.promote();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            randomBureaucrat.promote(); 
            cout << randomBureaucrat << endl;
            randomBureaucrat.demote();
            randomBureaucrat.demote();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}