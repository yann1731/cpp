#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default scavtrap constructor called" << std::endl;
	_name = "Marvin";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "Detailed scavtrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav)
{
	std::cout << "Copy scavtrap constructor called" << std::endl;
	_name = scav._name;
	_hitPoints = scav._hitPoints;
	_energyPoints = scav._energyPoints;
	_attackDamage = scav._attackDamage;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Default scavtrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << _name << " is now in Gate KeeperTM mode!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav)
{
	this->_name = scav._name;
	this->_hitPoints = scav._hitPoints;
	this->_energyPoints = scav._energyPoints;
	this->_attackDamage = scav._attackDamage;
	return (*this);
}