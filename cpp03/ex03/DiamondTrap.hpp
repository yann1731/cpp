#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &trap);
	~DiamondTrap();
	void attack(const std::string &target);
	void whoAmI(void);
	DiamondTrap &operator=(const DiamondTrap &trap);
};

#endif