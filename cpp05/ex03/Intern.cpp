#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Form *Intern::makeForm(const std::string form, const std::string target)
{
	int opt = -1;
	std::string funcs[] = {"shrubbery request", "robotomy request", "presidential pardon request"};

	for (int i = 0; i < 3; i++) {
		if (funcs[i] == form)
			opt = i;
	}
	switch (opt) {
		case (1):
			return makeShrubberyForm(target);
			break;
		case (2):
			return makeRobotomizeForm(target);
			break;
		case (3):
			return makePardonForm(target);
			break;
		default:
			throw NotAValidForm();
	}
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