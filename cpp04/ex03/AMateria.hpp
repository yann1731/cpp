// #ifndef AMATERIA_HPP
// # define AMATERIA_HPP
#pragma once
# include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	virtual std::string const & getType() const = 0; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual ~AMateria() = 0;
	virtual void use(ICharacter& target) = 0;
};

// #endif