#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

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
		const char *what() throw()
		{
			return "Exception: Grade too high!";
		}
	};
	class GradeTooLowException: public std::exception
	{
		const char *what() throw()
		{
			return "Exception: Grade too low!";
		}
	};
	void promote(void);
	void demote(void);
};

#endif