#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &src);
	std::string getName(void) const;
	int getGrade(void) const;
	class GradeTooHighException: public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char *what() const throw();
	};
	void signForm(Form &src) const;
	void promote(void);
	void demote(void);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);


#endif