#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat chadMarvin("Chad Marvin the first", 1);
        Bureaucrat bottomFeeder("Cletus Bottomfeeder", 150);
    
        Intern henchmanno1;

        Form *form;
        form = henchmanno1.makeForm("shrubbery request", "file");
        PresidentialPardonForm pardon("Ford prefect");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm arthur("Arthur Dent");

        form->beSigned(chadMarvin);
        form->execute(chadMarvin);

        shrub.beSigned(chadMarvin);
        shrub.execute(chadMarvin);

        arthur.beSigned(chadMarvin);
        arthur.execute(chadMarvin);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}