#include "Character.hpp"

Character::Character() {
	_name = "RandomCharacter";
	n_materias = 0;
}

Character::Character(const std::string& name) {
	_name = name;
	n_materias = 0;
}

Character::Character(const Character& src) {
	this->_name = src._name;
	this->n_materias = src.n_materias;
	for (unsigned int i = 0; i < src.n_materias; i++) {
		this->materias[i] = src.materias[i];
	}
}


Character::~Character() {
	for (unsigned int i = 0; i < n_materias; i++) {
		delete materias[i];
	}
}

Character &Character::operator=(const Character& rhs) {
	
}

void Character::equip(AMateria* m) {
	if (n_materias < 4) {
		materias[n_materias] = m;
		n_materias++;
	}
}

void Character::unequip(int idx) {
	droppedMaterias
}

void Character::use(int idx, ICharacter& target) {

}

std::string const &Character::getName(void) const {

}