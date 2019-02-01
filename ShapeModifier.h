#ifndef SHAPEMODIFIER_H
#define SHAPEMODIFIER_H

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

Polygon operator+(Polygon& lhs, Polygon& rhs);

Polygon operator+(Polygon& lhs, Triangle& rhs);
Polygon operator+(Triangle& lhs, Polygon& rhs);

Polygon operator+(Polygon& lhs, Line& rhs);
Polygon operator+(Line& lhs, Polygon& rhs);

Polygon operator+(Polygon& lhs, Point& rhs);
Polygon operator+(Point& lhs, Polygon& rhs);

Polygon operator+(Triangle& lhs, Triangle& rhs);

Polygon operator+(Triangle& lhs, Line& rhs);
Polygon operator+(Line& lhs, Triangle& rhs);

Polygon operator+(Triangle& lhs, Point& rhs);
Polygon operator+(Point& lhs, Triangle& rhs);

Polygon operator+(Line& lhs, Line& rhs);

Triangle operator+(Line& lhs, Point& rhs);
Triangle operator+(Point& lhs, Line& rhs);

Line operator+(Point& lhs, Point& rhs);


#endif