#include "square.h"

Square Square::subsquare(int dir)
{
    switch (dir) {
    case 0:
        return Square(x, y + w/2, w/2);
    case 1:
        return Square(x + w/2, y + w/2, w/2);
    case 2:
        return Square(x + w/2, y, w/2);
    case 3:
        return Square(x, y, w/2);
    default:
        throw new std::out_of_range("Not a valid direction: " + std::to_string(dir));
    }
}

bool Square::intersects_disk(Point_2D p, float r)
{
    // If p is in the square
    if (x <= p.x() && p.x() <= x + w && y <= p.y() && p.y() <= y + w)
        return true;
    // Else
    if (p.x() <= x) {
        if (p.y() <= y)
            return (distance2(x, y, p.x(), p.y()) <= r * r);
        else if (y + w <= p.y())
            return (distance2(x, y + w, p.x(), p.y()) <= r * r);
        else
            return (distance2(x, y + w/2, p.x(), p.y()) <= r * r);
    } else if (x + w <= p.x()) {
        if (p.y() <= y)
            return (distance2(x + w, y, p.x(), p.y()) <= r * r);
        else if (y + w <= p.y())
            return (distance2(x + w, y + w, p.x(), p.y()) <= r * r);
        else
            return (distance2(x + w, y + w/2, p.x(), p.y()) <= r * r);
    } else if (p.y() <= y)
        return (distance2(x + w/2, y, p.x(), p.y()) <= r * r);
    else
        return (distance2(x + w/2, y + w, p.x(), p.y()) <= r * r);
}
