#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie {
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	void announce (void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif //CPP_ZOMBIE_HPP
