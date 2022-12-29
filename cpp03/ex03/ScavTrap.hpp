#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scav);
	~ScavTrap();
	void guardGate(void);
	ScavTrap &operator=(const ScavTrap &scav);
};

#endif