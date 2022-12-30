#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat.type)
{
	std::cout << "Copy cat constructor called" << std::endl;
}

Cat::~Cat()
{
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
	type = src.type;
	return (*this);
}