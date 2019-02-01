#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape
{
public:
    Polygon();
    Polygon(Coordinates *arrayPoly, int sizeOfArray);
    Polygon(const Polygon& polygon);
    Polygon& operator=(const Polygon& polygon);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;
    friend std::ostream &operator<<(std::ostream&, const Polygon& polygon);
    friend Polygon operator+(const Polygon& polygon, const Coordinates& coordinates);

    Coordinates* getCoordinates() override;
    int getSize() override;
    
private:
    Coordinates *arrayPoly;
    int sizeOfArray;
};

#endif