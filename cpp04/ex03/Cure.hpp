#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure: public AMateria
{
private:

public:
	Cure();
	~Cure();
	Cure *clone() const;
	const std::string &getType() const;
	void use(ICharacter& id);
};

#endif