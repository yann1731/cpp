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
	std::cout << "Custom bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade)
{
	std::cout << "Copy bureaucrat constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	grade = src.grade;
	return (*this);
}