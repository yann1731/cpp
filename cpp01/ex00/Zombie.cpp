#include "Zombie.hpp"

Zombie(): name("Random Zombie") {
	return ;
}

Zombie::Zombie(std::string name): name(name) {
	return ;
}

void Zombie::announce() {
	std::cout << this->name << ": " << "Brainzzzzzz" << std::endl;
}

