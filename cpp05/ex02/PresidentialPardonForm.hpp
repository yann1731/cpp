#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	PresidentialPardonForm();
	std::string target;
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};

#endif