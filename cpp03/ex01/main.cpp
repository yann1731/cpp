#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap marvin;
	ScavTrap clapTrap("Claptrap");
	ScavTrap evilClap("Evil claptrap");
	ScavTrap clapClone = clapTrap;

	std::cout << clapTrap.getName() << std::endl;
	std::cout << clapClone.getName() << std::endl;
	std::cout << evilClap.getName() << std::endl;

	clapTrap.attack(evilClap.getName());
	evilClap.takeDamage(10);
	evilClap.beRepaired(10);

	clapTrap.guardGate();

	return (0);
}