#include "AMateria.hpp"

AMateria::~AMateria() {}

AMateria::AMateria() {
	this->type = "A Type";
}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}