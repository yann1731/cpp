#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
// • ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::order66(const Bureaucrat &executor) const
{
	std::string newTarget;
	newTarget = target;
	newTarget.append("_shrubbery");
	std::ofstream file(newTarget.c_str());
	file << "     *        *         *      " << std::endl;
	file << "    ***      ***       ***     " << std::endl;
	file << "   *****    *****     *****    " << std::endl;
	file << "  *******  *******   *******   " << std::endl;
	file << "     *        *         *      " << std::endl;
	file << "     *        *         *      " << std::endl;
	file << "     *        *         *      " << std::endl;
	executor.executeForm(*this);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->target = src.target;
	return *this;
}