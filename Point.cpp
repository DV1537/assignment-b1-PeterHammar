#include "Point.h"

std::string Point::getType()
{
    return "Point";
}

double Point::area()
{
    return -1;
}

double Point::circumference()
{
    return 0;
}

Coordinates Point::position() 
{
    Coordinates coordinates;
    int sumX = 0;
    int sumY = 0;
    for (int i = 0; i < sizeOfArray; i++)
    {
        sumX += arrayPoint[i].x; 
        sumY += arrayPoint[i].y; 
    }
    double avgX = static_cast<double>(sumX) / (sizeOfArray);
    double avgY = static_cast<double>(sumY) / (sizeOfArray);
    coordinates.x = avgX;
    coordinates.y = avgY;

    return coordinates;
}
Point::Point(Coordinates *array, int size)
{
    arrayPoint = array;
    sizeOfArray = size;
}

bool Point::isConvex()
{
    return false;
}

double Point::distance(Shape *s)
{
    double xDistance = s->position().x - this->position().x;
    double yDistance = s->position().y - this->position().y;
    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}

int Point::getSize()
{
    return sizeOfArray;
}

Coordinates* Point::getCoordinates()
{
    return arrayPoint;
}

Point::Point(const Point& point)
{
    sizeOfArray = point.sizeOfArray;
    arrayPoint = new Coordinates[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++)
    {
        arrayPoint[i] = point.arrayPoint[i];
    }
}


