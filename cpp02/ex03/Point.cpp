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

float Point::getX(void)
{
    return (x.toFloat());
}

float Point::getY(void)
{
    return (y.toFloat());
}

Point &Point::operator=(const Point &point)
{
    return (Point(point.x.toFloat(), point.y.toFloat()));
}