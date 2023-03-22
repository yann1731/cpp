#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	Character newme = Character("newme");
	Character newbob = Character("newbob");

	tmp = src->createMateria("ice");
	newbob.equip(tmp);
	tmp = src->createMateria("cure");
	newbob.equip(tmp);

	newme = newbob;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << &newbob << std::endl;
	std::cout << &newme << std::endl;

	newbob.use(0, *me);
	newbob.use(1, *me);
	
	delete bob;
	delete me;
	delete src;
	return 0;
}

