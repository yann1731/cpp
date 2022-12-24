#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(-1, "kevin");

	for (int i = 0; i < 20; i++)
		horde[i].announce();

	delete (horde);
	return (0);
}