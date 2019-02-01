#include "Line.h"

std::string Line::getType()
{
    return "Line";
}

double Line::area()
{
    return -1;
}

double Line::circumference()
{
    return 0;
}

Coordinates Line::position() 
{

    Coordinates coordinates;
    int sumX = 0;
    int sumY = 0;
    for (int i = 0; i < sizeOfArray; i++)
    {
        sumX += arrayLine[i].x; // 
        sumY += arrayLine[i].y; //
    }
    double avgX = static_cast<double>(sumX) / (sizeOfArray);
    double avgY = static_cast<double>(sumY) / (sizeOfArray);
    coordinates.x = avgX;
    coordinates.y = avgY;

    return coordinates;
}

Line::Line(Coordinates *array, int size)
{
    arrayLine = array;
    sizeOfArray = size;
}

bool Line::isConvex()
{
    return false;
}

double Line::distance(Shape *s)
{
    double xDistance = s->position().x - this->position().x;
    double yDistance = s->position().y - this->position().y;
    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}

int Line::getSize()
{
    return sizeOfArray;
}
Coordinates* Line::getCoordinates()
{ 
    return arrayLine;
}

Line::Line(const Line& line)
{
    sizeOfArray = line.sizeOfArray;
    arrayLine = new Coordinates[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++)
    {
        arrayLine[i] = line.arrayLine[i];
    }
}

