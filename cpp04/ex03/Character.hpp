#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	std::string _name;
	AMateria* inventory[4];
	AMateria* droppedMaterias[256];
public:
	Character();
	Character(const std::string& name);
	Character(const Character& src);
	~Character();
	Character &operator=(const Character& rhs);
	std::string const & getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif