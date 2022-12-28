#include "Point.hpp"

bool bsp(Point a, Point b, Point c, Point point);
int main( void )
{
    Point a(10.0, 10.0);
    Point b(5.25, 5.25);
    Point c(14.0, 2.42);
    Point point(8, 9);

    std::cout << bsp(a, b, c, point);
    return 0;
}