#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string type);
	std::string &getType(void);
	void setType(std::string type);
	~Weapon();
};


#endif