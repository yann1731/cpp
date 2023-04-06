#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("Bug"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
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

void Bureaucrat::executeForm(const Form &form) const
{
	std::cout << this->name << " executed " << form.getName() << std::endl;
}

void Bureaucrat::promote(void)
{
	if (grade - 1 <= 0)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::demote(void)
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low!");
}

void Bureaucrat::signForm(Form &src) const
{
	if (src.getSignStatus() == false) {
		try
		{
			src.beSigned(*this);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (src.getSignStatus() == false)
			std::cout << this->getName() << " could not sign form " << src.getName() << " because grade is insufficient" << std::endl;
		else
			std::cout << this->getName() << " has signed form " << src.getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}