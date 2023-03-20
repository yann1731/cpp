#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() {
	_name = "RandomCharacter";
	for (unsigned int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	for (unsigned int i = 0; i < 256; i++) {
		droppedMaterias[i] = NULL;
	}
}

Character::Character(const std::string& name) {
	_name = name;
	for (unsigned int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	for (unsigned int i = 0; i < 256; i++) {
		droppedMaterias[i] = NULL;
	}
}

Character::Character(const Character& src) {
	this->_name = src._name;
	for (unsigned int i = 0; i < 4; i++) {
		this->inventory[i] = src.inventory[i];
	}
}


Character::~Character() {
	for (unsigned int i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
	}
	for (unsigned int i = 0; i < 256; i++) {
		if (droppedMaterias[i])
			delete droppedMaterias[i];
	}
}

Character &Character::operator=(const Character& rhs) {
	for (unsigned int i = 0; i < 4; i++) {
		
	}
}

void Character::equip(AMateria *m) {
	for (unsigned int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 4) {
		return ;
	}
	
}

void Character::use(int idx, ICharacter& target) {

}

std::string const &Character::getName(void) const {

}