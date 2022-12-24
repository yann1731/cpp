#include "Zombie.hpp"

Zombie::Zombie(): name("stupid ass zombie"){
	return ;
}

Zombie::Zombie(std::string name): name(name){
	return ;
}

void Zombie::announce(){
	std::cout << this->name << ": " << "Brainzzzzzz" << std::endl;
}

Zombie* newZombie(std::string name){
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}

void randomChump(std::string name){
	Zombie randomZombie(name);
	randomZombie.announce();
}