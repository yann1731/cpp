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

// Now, add the execute(Bureaucrat const & executor) const member function to
// the base form and implement a function to execute the form’s action of the concrete
// classes. You have to check that the form is signed and that the grade of the bureaucrat
// attempting to execute the form is high enough. Otherwise, throw an appropriate excep-
// tion.
// Whether you want to check the requirements in every concrete class or in the base
// class (then call another function to execute the form) is up to you. However, one way is
// prettier than the other one.

// Lastly, add the executeForm(Form const & form) member function to the Bureau-
// crat. It must attempt to execute the form. If it’s successful, print something like:
// <bureaucrat> executed <form>
// If not, print an explicit error message

bool PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSignStatus() == true && executor.getGrade() <= this->getGradeExec()) {
		std::cout << target << " has been pardoned by president Zaphod Beeblebrox." << std::endl;
		return true;
	}
	else {
		throw GradeTooLowException();
	}
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->target = src.target;
	return *this;
}
