#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	// virtual ~IMateriaSource() {}
	// virtual void learnMateria(AMateria*) = 0;
	// virtual AMateria* createMateria(std::string const & type) = 0;
private:
	Materia
public:
	MateriaSource();
	~MateriaSource();
	void learMateria(AMateria *mat);
	AMateria *createMateria(std::string const & type);
};

#endif