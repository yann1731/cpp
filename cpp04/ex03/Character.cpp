#include "Character.hpp"

Character::Character() {
	_name = "RandomCharacter";
	n_materias = 0;
}

Character::Character(const std::string& name) {
	_name = name;
	n_materias = 0;
}


Character::~Character() {
	for (unsigned int i = 0; i < n_materias; i++) {
		delete (materias + i);
	}
}

void Character::equip(AMateria* m) {
	materias + n_materias = m;
	n_materias++;
}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

}

std::string const &Character::getName(void) const {

}