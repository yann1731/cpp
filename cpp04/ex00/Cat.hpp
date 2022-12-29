#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal
{
public:
    Cat();
    Cat(const std::string &type);
    Animal(const Animal &animal);
    ~Animal();
    std::string getType(void) const;
    Animal &operator=(const Animal &src);
};

#endif