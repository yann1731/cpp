#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria
{
private:

public:
	Ice();
	~Ice();
	Ice *clone() const;
	const std::string &getType() const;
	void use(ICharacter& id);
};

#endif