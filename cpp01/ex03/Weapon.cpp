#include "Weapon.hpp"

Weapon::Weapon():_type("default weapon"){
	return ;
}

Weapon::Weapon(std::string type): _type(type){
	return ;
}

Weapon::Weapon(const Weapon &weapon): _type(weapon._type){
	return ;
}

Weapon::~Weapon(){
	return ;
}

const std::string &Weapon::getType(void){
	return (this->_type);
}

void Weapon::setType(std::string &type){
	this->_type = type;
}