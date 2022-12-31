#include "Bureaucrat.hpp"

// class Bureaucrat
// {
// private:
// 	const std::string name;
// 	int grade;
// public:
// 	Bureaucrat();
// 	Bureaucrat(const std::string &name);
// 	Bureaucrat(const Bureaucrat &src);
// 	~Bureaucrat();
// 	Bureaucrat &operator=(const Bureaucrat &src);
// 	std::string getName(void) const;
// 	int getGrade(void) const;
// 	void promote(void);
// 	void demote(void);
// };

Bureaucrat::Bureaucrat(): name("Marvin"), grade(150)
{
	std::cout << "They're bureaucrats Morty, I don't respect them! -Rick Sanchez" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
	std::cout << "Custom bureaucrat constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
	std::cout << "Copy bureaucrat constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	grade = src.grade;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::promote(void)
{
	grade--;
	if (grade <= 0)
		throw GradeTooHighException();
}

void Bureaucrat::demote(void)
{
	grade++;
	if (grade > 150)
		throw GradeTooLowException();
}