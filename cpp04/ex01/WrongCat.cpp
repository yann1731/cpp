#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("tjwrejwef") 
{
	std::cout << "Default wrongcat constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type): WrongAnimal(type)
{
	std::cout << "Custom wrongcat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src.type)
{
	std::cout << "Copy wrongcat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Default wrongcat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "hello I'm a cat and I go quack quack" << std::endl;
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