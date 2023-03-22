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
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(2, *me);
	me->use(3, *me);

	me->unequip(3);
	me->unequip(2);

	me->use(1, *me);
	me->use(2, *me);

	ICharacter* bob = new Character("bob");

	Character *newme = new Character("newme");
	Character *newbob = new Character("newbob");

	tmp = src->createMateria("ice");
	newbob->equip(tmp);
	tmp = src->createMateria("cure");
	newbob->equip(tmp);

	*newme = *newbob;

	me->use(0, *bob);
	me->use(1, *bob);

	newbob->use(0, *me);
	newbob->use(1, *me);
	
	delete bob;
	delete me;
	delete src;
	delete newbob;
	delete newme;
	return 0;
}

