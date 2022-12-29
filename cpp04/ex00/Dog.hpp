#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal
{
public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &dog);
    ~Dog();
    void makeSound(void) const;
    std::string getType(void) const;
    Dog &operator=(const Dog &src);
};

#endif