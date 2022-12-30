#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	brain = new Brain;
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat.type)
{
	brain = new Brain;
	std::cout << "Copy cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Default cat destructor called" << std::endl;
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