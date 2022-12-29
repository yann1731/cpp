#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap myPal("Claptrap");
	ClapTrap badClap("Bad claptrap");
	ClapTrap marvin;

	myPal.attack(badClap.getName());
	badClap.takeDamage(0);
	badClap.beRepaired(0);	
	return (0);
}