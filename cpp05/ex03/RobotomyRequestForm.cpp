#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
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
	srand(time(NULL));
	int res;
	res = rand();
	res = res % 2;
	if (res == 0)
		std::cout << "*zzzzzzzzzztttt* " << target << " has been succesfully robotomized. Goodbye!" << std::endl;
	else
		std::cout << "*zzzzzzzzzztttt* " << target << "'s robotomization failed. Oh no" << std::endl;
	executor.executeForm(*this); 
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->target = src.target;
	return *this;
}
