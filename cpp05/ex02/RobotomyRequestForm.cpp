#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
// • RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45)
{
	std::cout << "Default robotomy request form constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("Robotomy Request Form", 72, 45)
{
	this->target = target;
	std::cout << "target robotomy request form constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src)
{
	std::cout << "Copy robotomy request form constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default robotomy request form destructor called" << std::endl;
}

void RobotomyRequestForm::order66(const Bureaucrat &executor) const
{
	std::cout << target << " *zzzzzzzzzztttt*. You have been succesfully robotomized. Goodbye!" << std::endl;
	executor.executeForm(*this);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->target = src.target;
	return *this;
}
