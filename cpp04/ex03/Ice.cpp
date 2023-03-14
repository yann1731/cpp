#include "Ice.hpp"

Ice::Ice() {
	type = "Ice";
}

Ice *Ice::clone() const {
	return (new Ice);
}

const std::string &Ice::getType() const {
	return this->type;
}

void Ice::use(ICharacter& id) {
	std::cout << "* shoots an ice bolt at " << id.getName() << " *"<< std::endl;
}