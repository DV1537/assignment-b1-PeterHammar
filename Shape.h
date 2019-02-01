#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <string>

class Coordinates
{
  public:
    double x;
    double y;
};

class Shape
{
  public:
    virtual std::string getType() = 0;
    virtual double area() = 0;
    virtual double circumference() = 0;
    virtual Coordinates position() = 0;
    virtual bool isConvex() = 0;
    virtual double distance(Shape *s) = 0;
    virtual Coordinates* getCoordinates() = 0;
    virtual int getSize() = 0; 

};

#endif