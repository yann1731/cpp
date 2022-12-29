#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    ClapTrap::_name = "Marvin_clap_name";
    _name = "Marvin";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
    ClapTrap::_name = name + "_clap_name";
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &trap)
{
    ClapTrap::_name = trap._name + "_clap_name";
    _name = trap._name;
    _hitPoints = trap._hitPoints;
    _energyPoints = trap._energyPoints;
    _attackDamage = trap._attackDamage;
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "ClapTrap name: " << ClapTrap::_name << "DiamondTrap name: " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &trap)
{
    _name = trap._name;
    _hitPoints = trap._hitPoints;
    _energyPoints = trap._energyPoints;
    _attackDamage = trap._attackDamage;
    return (*this);
}