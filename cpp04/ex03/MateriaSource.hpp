#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	// virtual ~IMateriaSource() {}
	// virtual void learnMateria(AMateria*) = 0;
	// virtual AMateria* createMateria(std::string const & type) = 0;
private:
	AMateria* inventory[4];
public:
	MateriaSource();
	~MateriaSource();
	void learMateria(AMateria *mat);
	AMateria *createMateria(std::string const & type);
};

#endif