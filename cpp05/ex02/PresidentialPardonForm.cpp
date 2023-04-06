#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
// • PresidentialPardonForm: Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.
// All of them take only one parameter in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home.

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("Presidential Pardon Form", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src), target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	std::cout << target << " has been pardoned by president Zaphod Beeblebrox." << std::endl;
	executor.executeForm(*this); 
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->target = src.target;
	return *this;
}
