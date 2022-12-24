#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie = new Zombie("Pinky");

	Zombie *heapFunctionZombie = newZombie("The brain");
	randomChump("Kevin");
	Zombie randomZombie;

	randomZombie.announce();
	heapZombie->announce();
	heapFunctionZombie->announce();

	delete(heapZombie);
	delete(heapFunctionZombie);
	return (0);
}