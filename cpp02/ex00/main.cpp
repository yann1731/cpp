#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    a.setRawBits(20);
    Fixed b( a );
    b.setRawBits(10);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}