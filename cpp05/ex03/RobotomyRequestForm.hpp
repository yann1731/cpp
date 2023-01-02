#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	RobotomyRequestForm();
	std::string target;
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	void order66(const Bureaucrat &executor) const;
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
};

#endif