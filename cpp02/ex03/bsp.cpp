#include "Point.hpp"

float getW1(Point const a, Point const b, Point const c, Point const p)
{
    float w1;

    w1 = (a.getX() * (c.getY() - a.getY()) + (p.getY() - a.getY()) * (c.getX() - a.getX()) - p.getX() * (c.getY() - a.getY())) / ((b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()));
    return (w1);
}

float getW2(Point const a, Point const b, Point const c, Point const p, float w1)
{
    float w2;

    w2 = (p.getY() - a.getY() - w1 * (b.getY() - a.getY())) / (c.getY() - a.getY());
    return (w2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float w1 = getW1(a, b, c, point);
    float w2 = getW2(a, b, c, point, w1);

    if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
        return (true);
    return (false);
}
