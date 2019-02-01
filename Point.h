#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point : public Shape
{
public:
    Point();
    Point(Coordinates *arrayPoint, int sizeOfArray);
    Point(const Point& point);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;

    int getSize() override;
    Coordinates* getCoordinates() override;
private:
    Coordinates *arrayPoint;
    int sizeOfArray;
};

#endif
