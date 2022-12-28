#include "Point.hpp"

Point::Point():x(0), y(0)
{
}

Point::Point(const Point &point): x(point.x), y(point.y)
{   
}

Point::Point(const float x, const float y): x(x), y(y)
{
}

Point::~Point()
{
}

float Point::getX(void) const
{
    return (x.toFloat());
}

float Point::getY(void) const
{
    return (y.toFloat());
}

Point &Point::operator=(const Point &point)
{
    (void)point;
    return (*this);
}