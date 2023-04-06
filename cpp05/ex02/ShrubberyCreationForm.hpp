#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm: public Form
{
private:
	ShrubberyCreationForm();
	std::string target;
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat &executor) const;
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
};

#endif