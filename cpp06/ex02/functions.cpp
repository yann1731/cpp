#include "functions.hpp"

/*It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.*/
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

/*It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
void identify(Base *p)
{

}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.*/
void identify(Base &p)
{

}