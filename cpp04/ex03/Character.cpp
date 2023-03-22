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
	*this = src;
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
	this->_name = rhs._name;
	for (unsigned int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
	for (unsigned int i = 0; i < 4; i++) {
		if (rhs.inventory[i])
			this->inventory[i] = rhs.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return *this;
}

void Character::equip(AMateria *m) {
	for (unsigned int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		return ;
	}
	for (unsigned int i = 0; i < 256; i++) {
		if (!droppedMaterias[i]) {
			droppedMaterias[i] = inventory[idx];
			inventory[idx] = NULL;
			return ;
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		return ;
	}
	else {
		if (inventory[idx])
			inventory[idx]->use(target);
	}
}

std::string const &Character::getName(void) const {
	return this->_name;
}