#include "Triangle.h"
#include <iostream>

std::string Triangle::getType()
{   
    return "Triangle";
}
double Triangle::area()
{
    // A = 1/2|(xA−xC)(yB−yA)−(xA−xB)(yC−yA)|

    double xa = arrayTriangle[0].x;
    double xb = arrayTriangle[1].x;
    double xc = arrayTriangle[2].x;
    double ya = arrayTriangle[0].y;
    double yb = arrayTriangle[1].y;
    double yc = arrayTriangle[2].y;
    
    double triangleArea = 0.5*(abs((xa - xc)*(yb - ya) - (xa - xb)*(yc - ya)));

    return triangleArea;
}

double Triangle::circumference()
{
    double circumferenceTriangle = 0;
    //sqrt(x1-x0)^2 + (y1-y0)^2 osv
    for(int i = 0; i < sizeOfArray-1; i++)
    {
        circumferenceTriangle += sqrt(pow((arrayTriangle[i+1].x-arrayTriangle[i].x), 2.0)+pow((arrayTriangle[i+1].y-arrayTriangle[i].y), 2.0));
    }
 
    circumferenceTriangle += sqrt(pow((arrayTriangle[0].x-arrayTriangle[sizeOfArray-1].x), 2.0)
                            +pow((arrayTriangle[0].y-arrayTriangle[sizeOfArray-1].y), 2.0));

    return circumferenceTriangle;

}

Coordinates Triangle::position() 
{
    Coordinates coordinates;
    //sum of coordinates divided by amount of coordinates
    coordinates.x = (arrayTriangle[0].x + arrayTriangle[1].x + arrayTriangle[2].x)/3;
    coordinates.y = (arrayTriangle[0].y + arrayTriangle[1].y + arrayTriangle[2].y)/3;
    return coordinates;
}

Triangle::Triangle(const Triangle& triangle)
{
    sizeOfArray = triangle.sizeOfArray;
    arrayTriangle = new Coordinates[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++)
    {
        arrayTriangle[i] = triangle.arrayTriangle[i];
    }
}

Triangle::Triangle(Coordinates *array, int size)
{
    arrayTriangle = array;
    sizeOfArray = size;
}

bool Triangle::isConvex()
{
    return false;
}

double Triangle::distance(Shape *s)
{
    double xDistance = s->position().x - this->position().x;
    double yDistance = s->position().y - this->position().y;
    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}

int Triangle::getSize()
{
    return sizeOfArray;
}

Coordinates* Triangle::getCoordinates()
{ 
    return arrayTriangle;
}