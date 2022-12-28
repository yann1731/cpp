#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &point);
    ~Point();
    float getX(void) const;
    float getY(void) const;
    Point &operator= (const Point &point);
};

#endif