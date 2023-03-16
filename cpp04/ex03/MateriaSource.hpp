#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	// virtual ~IMateriaSource() {}
private:
	AMateria* inventory[4];
public:
	MateriaSource();
	~MateriaSource();
	void learnMateria(AMateria *mat);
	AMateria *createMateria(std::string const & type);
};

#endif