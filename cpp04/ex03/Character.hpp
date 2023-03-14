#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AMateria.hpp"

class Character
{
private:
	std::string _name;
	AMateria* materias;
	unsigned int n_materias;
public:
	Character();
	Character(const std::string& name);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif