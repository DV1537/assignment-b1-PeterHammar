#include "Shape.h"

std::ostream& operator<<(std::ostream& os, const Coordinates& rhs)
{
    os << "(" << rhs.x << ", " << rhs.y << ")";
    return os;
}



