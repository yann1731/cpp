#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	~WrongCat();
	void makeSound(void) const;
	std::string getType(void) const;
	WrongCat &operator=(const WrongCat &src);
};

#endif