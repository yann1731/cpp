#ifndef INTERN_HPP
#define INTERN_HPP
# include <iostream>
# include "Form.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Form *makeForm(const std::string form, const std::string target);
};

#endif