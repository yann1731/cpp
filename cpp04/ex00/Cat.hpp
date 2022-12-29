#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal
{
public:
    Cat();
    Cat(const std::string &type);
    Cat(const Cat &cat);
    ~Cat();
    void makeSound(void);
    std::string getType(void) const;
    Cat &operator=(const Cat &src);
};

#endif