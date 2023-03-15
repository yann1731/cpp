#include "Cure.hpp"

Cure::Cure() {
	this->type = "Cure";
}

Cure *Cure::clone() const {
	return (new Cure);
}

const std::string &Cure::getType() const {
	return this->type;
}

void Cure::use(ICharacter& id) {
	std::cout << "* heals " << id.getName() << "'s wounds *" << std::endl;
}