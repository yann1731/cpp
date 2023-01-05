#include "functions.hpp"

int main(void)
{
    Base *p;

    p = generate();
    identify(p);
    identify(*p);
    return 0;
}