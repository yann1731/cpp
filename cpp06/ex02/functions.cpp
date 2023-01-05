#include "functions.hpp"

Base *generate(void)
{
    int res;
    Base *p;
    srand(time(NULL));
    res = rand() % 3 + 1;

    if (res == 1)
        return p = new A;
    else if (res == 2)
        return p = new B;
    else
        return p = new C;
}

void identify(Base *p)
{
    A *a;
    B *b;
    C *c;

    if (a = dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if(b = dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (c = dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.*/
void identify(Base &p)
{

}