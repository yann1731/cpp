#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

int main(void)
{
    try
    {
        Bureaucrat chadMarvin("Chad Marvin the first", 1);
        Bureaucrat bottomFeeder("Cletus Bottomfeeder", 150);
    
        PresidentialPardonForm ford("Ford prefect");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm arthur("Arthur Dent");

        cout << ford << endl;

        cout << shrub << endl;

        cout << arthur << endl;


        // form.beSigned(chadMarvin);
        // form.execute(chadMarvin);

        // shrub.beSigned(chadMarvin);
        // shrub.execute(chadMarvin);

        // try
        // {
        //     arthur.beSigned(chadMarvin);
        //     arthur.execute(bottomFeeder);  
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        // }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}