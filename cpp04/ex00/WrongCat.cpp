#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("tjwrejwef") {std::cout << "Default wronganimal constructor called" << std::endl;}

WrongCat::WrongCat(const std::string &type): WrongAnimal(type) {std::cout << "Custom wronganimal constructor called" << std::endl;}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src.type) {std::cout << "Copy wronganimal constructor called" << std::endl;}

WrongCat::~WrongCat() {}

void WrongCat::makeSound(void) const
{
	std::cout << "hello I'm a sheep and I go quack quack" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (type);
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	type = src.type;
	return (*this);
}