#include "Shapemodifier.h"
Coordinates* mergeCoordinateArrays(Coordinates* cArray1, int size1, Coordinates* cArray2, int size2)
{
    Coordinates * newArray = new Coordinates[size1+size2];
    for(int i = 0; i < size1; i++)
    {
        newArray[i] = cArray1[i];
    }
    for(int i = size1; i < (size1+size2); i++)
    {
        newArray[i] = cArray2[i-size1];
    }
    return newArray;
}

Polygon operator+(Polygon& lhs, Polygon& rhs)
{   
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

        int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());
    
    Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Polygon& lhs, Triangle& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Triangle& lhs, Polygon& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}


Polygon operator+(Polygon& lhs, Line& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Line& lhs, Polygon& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Polygon& lhs, Point& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Point& lhs, Polygon& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Triangle& lhs, Triangle& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Triangle& lhs, Line& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}
Polygon operator+(Line& lhs, Triangle& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Triangle& lhs, Point& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}
Polygon operator+(Point& lhs, Triangle& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Polygon operator+(Line& lhs, Line& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

            int sizeOfNewPolygon = (lhs.getSize() + rhs.getSize());


        Polygon newPolygon(newArray, sizeOfNewPolygon);

    return newPolygon;
}

Triangle operator+(Line& lhs, Point& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

    int sizeOfNewTriangle = lhs.getSize() + rhs.getSize();

    Triangle newTriangle(newArray, sizeOfNewTriangle);

    return newTriangle;
}

Triangle operator+(Point& lhs, Line& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

    int sizeOfNewTriangle = lhs.getSize() + rhs.getSize();

    Triangle newTriangle(newArray, sizeOfNewTriangle);

    return newTriangle;
}

Line operator+(Point& lhs, Point& rhs)
{
    Coordinates* newArray = mergeCoordinateArrays(
                            lhs.getCoordinates(), lhs.getSize(), 
                            rhs.getCoordinates(), rhs.getSize());

    int sizeOfNewLine = lhs.getSize() + rhs.getSize();

    Line newLine(newArray, sizeOfNewLine);

    return newLine;
}
