#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
	if (N > 0)
	{
		Zombie *zombieHorde = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombieHorde[i].setName(name);
		return (zombieHorde);
	}
	return (new(Zombie));
}