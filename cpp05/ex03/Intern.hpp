#ifndef INTERN_HPP
#define INTERN_HPP
# include <iostream>
# include "Form.hpp"
# include <exception>

class Intern
{
public:
	Intern();
	~Intern();
	Form *makeForm(const std::string form, const std::string target);
	Form *makeShrubberyForm(const std::string &target);
	Form *makeRobotomizeForm(const std::string &target);
	Form *makePardonForm(const std::string &target);

	class NotAValidForm: public std::exception {
		const char* what() const throw() {
			return "This is not a valid form!";
		}
	};
};

#endif