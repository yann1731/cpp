#include "FragTrap.hpp"

int main(void)
{
	FragTrap marvin;
	FragTrap clapTrap("Claptrap");
	FragTrap evilClap("Evil claptrap");
	FragTrap clapClone = clapTrap;

	std::cout << clapTrap.getName() << std::endl;
	std::cout << clapClone.getName() << std::endl;
	std::cout << evilClap.getName() << std::endl;

	clapTrap.attack(evilClap.getName());
	evilClap.takeDamage(10);
	evilClap.beRepaired(10);

	clapTrap.highFivesGuys();

	return (0);
}