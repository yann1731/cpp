#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name("Marvin"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &claptrap): _name(claptrap._name), _hitPoints(claptrap._hitPoints), _energyPoints(claptrap._energyPoints), _attackDamage(claptrap._attackDamage) {}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string &target)
{
	std::cout << _name << " attacks " << target << " for " << _attackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _name << " takes " << amount << " points of damage. Ouch" << std::endl;
	_hitPoints -= amount; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << _name << " is repaired for " << amount << " points of damage. Woohoo!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

std::string ClapTrap::getName (void)
{
	return (_name);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	this->_name = claptrap._name;
	this->_hitPoints = claptrap._hitPoints;
	this->_energyPoints = claptrap._energyPoints;
	this->_attackDamage = claptrap._attackDamage;
	return (*this);
}