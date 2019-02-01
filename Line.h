#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line();
    Line(Coordinates *arrayLine, int sizeOfArray);
    Line(const Line& line);
    std::string getType() override;
    double area() override;
    double circumference() override;
    Coordinates position() override;
    bool isConvex() override;
    double distance(Shape *s) override;

    Coordinates* getCoordinates() override;
    int getSize() override;

private:
    Coordinates *arrayLine;
    int sizeOfArray;
};

#endif