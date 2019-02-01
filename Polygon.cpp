#include <iostream>
#include <cmath>
using namespace std;
#include "Polygon.h"

std::string Polygon::getType()
{
    return "Polygon";
}

double Polygon::area()
{
    //koordinatareaformeln,
    //A = 1/2*abs((SUM(x[i] * (y[i-1]-y[i+1])))
    double polyArea = 0;
    for (int i = 1; i < sizeOfArray - 1; i++)
    {
        polyArea += arrayPoly[i].x * (arrayPoly[i + 1].y - arrayPoly[i - 1].y);
    }
    polyArea += arrayPoly[0].x * (arrayPoly[1].y - arrayPoly[sizeOfArray - 1].y);
    polyArea += arrayPoly[sizeOfArray-1].x*(arrayPoly[0].y-arrayPoly[sizeOfArray-2].y);

    if(polyArea < 0)
    {
        polyArea *= -1;
    }

    return polyArea/2;
}

double Polygon::circumference()
{
    double circumferencePoly = 0;
    //sqrt(x1-x0)^2 + (y1-y0)^2 osv
    for(int i = 0; i < sizeOfArray-1; i++)
    {
        circumferencePoly += sqrt(pow((arrayPoly[i+1].x-arrayPoly[i].x), 2.0)+pow((arrayPoly[i+1].y-arrayPoly[i].y), 2.0));
    }
 
    circumferencePoly += sqrt(pow((arrayPoly[0].x-arrayPoly[sizeOfArray-1].x), 2.0)
                            +pow((arrayPoly[0].y-arrayPoly[sizeOfArray-1].y), 2.0));

    return circumferencePoly;
}

Coordinates Polygon::position()
{

    Coordinates coordinates;
    int sumX = 0;
    int sumY = 0;
    for (int i = 0; i < sizeOfArray; i++)
    {
        sumX += arrayPoly[i].x; // 
        sumY += arrayPoly[i].y; //
    }
    double avgX = static_cast<double>(sumX) / (sizeOfArray);
    double avgY = static_cast<double>(sumY) / (sizeOfArray);
    coordinates.x = avgX;
    coordinates.y = avgY;

    return coordinates;
}

Polygon::Polygon(Coordinates *array, int size)
{
    arrayPoly = array;
    sizeOfArray = size;
}

bool Polygon::isConvex()
{
    // take three points
    // create two vectors: one from point1 -> point2, one from point2 -> point3
    // calculate rotation between the vector using cross product
    // check sign of z-axis of cross product: 
    // (a = [ax,ay,ax], b = [bx,by,bz] =>  a x b = [_ ,_ , ax*by - ay*bx])
    // compare sign with previous cross product, if same OK (or if sign = 0), otherwise stop and return false
    // redo if not all points are checked
    // if all signs are the same (or z-axis component == 0), return true

    bool isConvex = true;
    int previousRotation = 0;
    double angle = 0;
    for(int i = 0; i < sizeOfArray; i++)
    {
        int ax = (arrayPoly[(i+1) % sizeOfArray].x-arrayPoly[i % sizeOfArray].x);
        int by = (arrayPoly[(i+2) % sizeOfArray].y-arrayPoly[(i+1) % sizeOfArray].y);
        int ay = (arrayPoly[(i+1) % sizeOfArray].y-arrayPoly[i % sizeOfArray].y);
        int bx = (arrayPoly[(i+2) % sizeOfArray].x-arrayPoly[(i+1) % sizeOfArray].x);
        int rotation = ax*by-ay*bx;
        int scalar = ax*bx+ay*by;

        /**
         * Just like the dot product is proportional to the cosine of the angle, 
         * the determinant is proprortional to its sine. 
         * 
         * And if you know the cosine and the sine, then you can compute the angle. 
         * Many programming languages provide a function atan2 for this purpose, e.g.:
         * dot = x1*x2 + y1*y2      # dot product
         * det = x1*y2 - y1*x2      # determinant
         * angle = atan2(det, dot)  # atan2(y, x) or atan2(sin, cos)
        */
        const double pi = 3.14159265;
        angle += std::atan2(rotation, scalar) * 180.0 / pi;
        if(angle > 400 || angle < -400)
        {
            isConvex = false;
            break;
        }

        if(i == 0)
        {
            previousRotation = rotation;
        }
        else if (rotation != 0)
        {
            if (previousRotation != 0)
            {
                if (rotation < 0 && previousRotation > 0)
                {
                    isConvex = false;
                    break;
                }
                else if (rotation > 0 && previousRotation < 0)
                {
                    isConvex = false;
                    break;
                }
            }
            previousRotation = rotation;
        }
    }
    return isConvex;
}

double Polygon::distance(Shape *s)
{
    double xDistance = s->position().x - this->position().x;
    double yDistance = s->position().y - this->position().y;
    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}

std::ostream &operator<<(std::ostream& os, const Polygon& polygon)
{
    for(int i = 0; i < polygon.sizeOfArray; i++)
    {
       os << polygon.arrayPoly[i].x << " " << polygon.arrayPoly[i].y << '\n'; 
    }
    return os;
}

Polygon operator+(const Polygon& polygon, const Coordinates& coordinates)
{
    Polygon newPolygon(nullptr, 0);
    
    newPolygon = polygon;
    newPolygon.sizeOfArray += 1;
    Coordinates * newArray = new Coordinates[newPolygon.sizeOfArray];
    for(int i = 0; i < newPolygon.sizeOfArray-1; i++)
    {
        newArray[i] = newPolygon.arrayPoly[i];
    }
    delete[] newPolygon.arrayPoly;
    newArray[newPolygon.sizeOfArray-1] = coordinates;
    newPolygon.arrayPoly = newArray;
    return newPolygon;
}

Polygon& Polygon::operator=(const Polygon& polygon)
{
    if(this == &polygon)
    {
        return *this;
    }
    this->sizeOfArray = polygon.sizeOfArray;
    delete[] arrayPoly;
    this->arrayPoly = new Coordinates[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++)
    {
        this->arrayPoly[i] = polygon.arrayPoly[i];
    }
    return *this;
}

Polygon::Polygon(const Polygon& polygon)
{
    sizeOfArray = polygon.sizeOfArray;
    arrayPoly = new Coordinates[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++)
    {
        arrayPoly[i] = polygon.arrayPoly[i];
    }
}

Polygon::Polygon()
{
    arrayPoly = nullptr;
    sizeOfArray = 0;
}

Coordinates* Polygon::getCoordinates()
{
    return arrayPoly;
}

int Polygon::getSize()
{
    return sizeOfArray;
}