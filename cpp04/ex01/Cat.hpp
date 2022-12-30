#ifndef CAT_HPP
#define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat &cat);
    ~Cat();
    void makeSound(void) const;
    std::string getType(void) const;
    Cat &operator=(const Cat &src);
};

#endif