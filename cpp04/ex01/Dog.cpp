#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	brain = new Brain;
	std::cout << "Default dog constructor called" << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog.type)
{
	brain = new Brain;
	std::cout << "Copy dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Default dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "fuck c++... I mean woof" << std::endl;
}

std::string Dog::getType(void) const
{
	return (type);
}

Dog &Dog::operator=(const Dog &src)
{
	brain = src.brain;
	type = src.type;
	return (*this);
}