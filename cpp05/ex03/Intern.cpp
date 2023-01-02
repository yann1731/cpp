#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Default Intern destructor called" << std::endl;
}

Form *Intern::makeForm(const std::string form, const std::string target)
{
	Form *newForm = new ShrubberyCreationForm(target);
}