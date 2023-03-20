#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (unsigned int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (unsigned int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* mat) {
    for (unsigned int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = mat;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (unsigned int i = 0; i < 4; i++) {
        if (inventory[i]) {
            if (inventory[i]->getType().compare(type) == 0) {
                return inventory[i]->clone();
            }
        }
    }
    return NULL;
}