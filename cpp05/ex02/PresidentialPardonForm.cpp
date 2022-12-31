#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
// • PresidentialPardonForm: Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.
// All of them take only one parameter in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home.

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5)
{
	std::cout << "Default presidential pardon form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("Presidential Pardon Form", 25, 5)
{
	this->target = target;
	std::cout << "Target presidential pardon form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src)
{
	std::cout << "Copy presidential pardon form constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default presidential pardon form destructor called" << std::endl;
}

void PresidentialPardonForm::order66(const Bureaucrat &executor) const
{
	std::cout << target << " has been pardoned by president Zaphod Beeblebrox." << std::endl;
	executor.executeForm(*this); 
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	*this = src;
	return *this;
}
