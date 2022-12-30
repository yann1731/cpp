#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default fragtrap constructor called" << std::endl;
	_name = "Marvin";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "Detailed fragtrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &scav)
{
	std::cout << "Copy fragtrap constructor called" << std::endl;
	_name = scav._name;
	_hitPoints = scav._hitPoints;
	_energyPoints = scav._energyPoints;
	_attackDamage = scav._attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "Default fragtrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five guys! Come on don't leave me hanging" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &scav)
{
	this->_name = scav._name;
	this->_hitPoints = scav._hitPoints;
	this->_energyPoints = scav._energyPoints;
	this->_attackDamage = scav._attackDamage;
	return (*this);
}