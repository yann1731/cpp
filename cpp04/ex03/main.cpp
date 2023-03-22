#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "Learn materia called" << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout << "AMateria tmp declared" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << "CreateMateria called" << std::endl;
	me->equip(tmp);
	std::cout << "me equipping tmp" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	ICharacter* bob2 = new Character;
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

