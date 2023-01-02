#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal();
	virtual void makeSound(void) const;
	std::string getType(void) const;
	WrongAnimal &operator=(const WrongAnimal &src);
};

#endif