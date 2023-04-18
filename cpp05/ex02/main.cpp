#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

int main(void)
{
    Bureaucrat chadMarvin("Chad Marvin the first", 1);
    Bureaucrat bottomFeeder("Cletus Bottomfeeder", 150);

    PresidentialPardonForm ford("Ford prefect");
    ShrubberyCreationForm shrub("shrub");
    RobotomyRequestForm arthur("Arthur Dent");
    // cout << ford << endl;
    // cout << shrub << endl;
    // cout << arthur << endl;
    try
    {
        chadMarvin.signForm(ford);
        chadMarvin.executeForm(ford);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        chadMarvin.signForm(shrub);
        chadMarvin.executeForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        bottomFeeder.signForm(arthur);
        bottomFeeder.executeForm(arthur);  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        chadMarvin.signForm(arthur);
        chadMarvin.executeForm(arthur);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
        
    
    return 0;
}