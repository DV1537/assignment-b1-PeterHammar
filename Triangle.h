#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(Coordinates *arrayTriangle, int sizeOfArray);
    Triangle(const Triangle& triangle);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;

    Coordinates* getCoordinates() override;
    int getSize() override;
private:
    Coordinates *arrayTriangle;
    int sizeOfArray;
};

#endif