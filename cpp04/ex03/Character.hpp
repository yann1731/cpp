#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AMateria.hpp"

class Character: public ICharacter
{
private:
	Character();
	std::string _name;
	AMateria* materias[4];
	unsigned int n_materias;
	AMateria* droppedMaterias[256];
	unsigned int n_dropped_materias;
public:
	Character(const std::string& name);
	Character(const Character& src);
	~Character();
	Character &operator=(const Character& rhs);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif