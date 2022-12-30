#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default cat constructor called" << std::endl;
	type = "cat";
	brain = new Brain;
}

Cat::Cat(const Cat &cat): Animal(cat.type)
{
	std::cout << "Copy cat constructor called" << std::endl;
	brain = new Brain;
}

Cat::~Cat()
{
	std::cout << "Default cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow" << std::endl;
}

std::string Cat::getType(void) const
{
	return (type);
}

Cat &Cat::operator=(const Cat &src)
{
	brain = src.brain;
	type = src.type;
	return (*this);
}