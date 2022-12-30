#include "Animal.hpp"

Animal::Animal(): type("capybara")
{
    std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type): type(type)
{
    std::cout << "Custom animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src): type(src.type)
{
    std::cout << "Copy animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Default animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    this->type = src.type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (type);
}

std::ostream &operator<<(std::ostream &out, const Animal &src)
{
    out << src.getType();
    return out;
}