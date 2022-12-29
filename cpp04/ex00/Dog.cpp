#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {std::cout << "Default dog constructor called" << std::endl;}

Dog::Dog(const std::string &type): Animal("Dog") {(void) type; std::cout << "Custom dog constructor called(not that it matters)" << std::endl;}

Dog::Dog(const Dog &dog): Animal(dog.type) {std::cout << "Copy dog constructor called" << std::endl;}

Dog::~Dog() {std::cout << "Default dog destructor called" << std::endl;}

void Dog::makeSound(void)
{
	std::cout << "Woof woof" << std::endl;
}

std::string Dog::getType(void) const
{
	return (type);
}

Dog &Dog::operator=(const Dog &src)
{
	type = src.type;
	return (*this);
}