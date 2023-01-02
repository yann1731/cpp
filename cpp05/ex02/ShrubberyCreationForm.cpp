#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
// • ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", 145, 137)
{
	std::cout << "Default shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
	std::cout << "Default shrubberycreationform contructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src)
{
	std::cout << "Copy shrubberycreationform constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default shrubberycreationform destructor called" << std::endl;
}

void ShrubberyCreationForm::order66(const Bureaucrat &executor) const
{
	std::cout << target << " has planted shrubberies" << std::endl;
	executor.executeForm(*this);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->target = src.target;
	return *this;
}