#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default dog constructor called" << std::endl;
	type = "dog";
	brain = new Brain;
}

Dog::Dog(const Dog &dog): Animal(dog.type)
{
	std::cout << "Copy dog constructor called" << std::endl;
	brain = new Brain;
	this->brain = dog.brain;
}

Dog::~Dog()
{
	std::cout << "Default dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
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