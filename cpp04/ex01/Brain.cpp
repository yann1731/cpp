#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "food";
	}
}

Brain::Brain(const Brain &src)
{
	std::cout << "Copy brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = src.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Default brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = src.ideas[i];
	}
	return (*this);
}