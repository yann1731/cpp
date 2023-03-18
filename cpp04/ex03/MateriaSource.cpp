#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (unsigned int i = 0; i < 4; i++) {
        inventory[i] = nullptr;
    }
}

MateriaSource::~MateriaSource() {
    for (unsigned int i = 0; i < 4; i++) {
        if (inventory[i])
            delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* mat) {
    for (unsigned int i = 0; i < 4; i++) {
        if (!inventory[i])
            inventory[i] = mat->clone();
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (unsigned int i = 0; i < 4; i++) {
        if (inventory[i]->getType() == type) {
            return inventory[i]->clone();
        }
    }
}