#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Intern();
// 	~Intern();
// 	Form *makeForm(const std::string form, const std::string target);
// 	Form *makeShrubberyForm(const std::string &target);
// 	Form *makeRobotomizeForm(const std::string &target);
// 	Form *makePardonForm(const std::string &target);

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Default Intern destructor called" << std::endl;
}

// void (Harl::*complaint[]) (void) =
// 	{
// 		&Harl::debug,
// 		&Harl::info,
// 		&Harl::warning,
// 		&Harl::error
// 	};
// 	std::string levels[] =
// 	{
// 		"debug",
// 		"info",
// 		"warning",
// 		"error"
// 	};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		void (Harl::*adressComplaint) (void) = complaint[i];
// 		if (level == levels[i])
// 			(this->*adressComplaint)();
// 	}

Form *Intern::makeForm(const std::string form, const std::string target)
{
	std::string funcs[] = {"shrubbery request", "robotomy request", "presidential pardon request"};

	Form *(Intern::*getForm[]) (const std::string &target) =
	{
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomizeForm,
		&Intern::makePardonForm
	};

	Form *funcPointer (const std::string &target);
	for (int i = 0; i < 3; i++)
	{
		Form *(Intern::*dispatchForm) (const std::string &target) = getForm[i];
		if (funcs[i] == form)
		{
			return ((this->*dispatchForm) (target));
		}
	}
	return (NULL);
}

Form *Intern::makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomizeForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}