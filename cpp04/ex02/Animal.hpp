#ifndef ANIMAL_HPP
#define ANIMAL_HPP
# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const std::string &type);
    Animal(const Animal &animal);
    virtual ~Animal() = 0;
    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
    Animal &operator=(const Animal &src);
};
std::ostream &operator<<(std::ostream &out, const Animal &src);

#endif