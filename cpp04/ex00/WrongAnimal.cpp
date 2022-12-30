#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("tjwrejwef") {std::cout << "Default wronganimal constructor called" << std::endl;}

WrongAnimal::WrongAnimal(const std::string &type): type(type) {std::cout << "Custom wronganimal constructor called" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal &src): type(src.type) {std::cout << "Copy wronganimal constructor called" << std::endl;}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound(void) const
{
	std::cout << "hello I'm a sheep and I go orkwIFJWEFWkjfKJFDAKJHGEJFGdjksg" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	type = src.type;
	return (*this);
}