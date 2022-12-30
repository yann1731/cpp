#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog &dog);
    ~Dog();
    void makeSound(void) const;
    std::string getType(void) const;
    Dog &operator=(const Dog &src);
};

#endif