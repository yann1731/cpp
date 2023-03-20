#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *animalFarm[8];

	for (int i = 0; i < 8; i++)
	{
		if (i < 4)
			animalFarm[i] = new Cat();
		else
			animalFarm[i] = new Dog();
	}
	animalFarm[0]->makeSound();
	animalFarm[7]->makeSound();

	for (int i = 0; i < 8; i++)
		delete animalFarm[i];

return 0;
}