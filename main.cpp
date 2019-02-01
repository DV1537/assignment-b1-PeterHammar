#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "ShapeModifier.h"
#include "Figure.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Shape& defineShape(Coordinates *array, int sizeOfArray);
void printType(Shape *shape);
void printPosition(Shape *shape);
void printArea(Shape *shape);
void printCircumference(Shape *shape);

int main()
{
    float p;
    int sizeOfArray = 1;

    float *array = new float[sizeOfArray];

    ifstream myReadFile;

    myReadFile.open("a2.txt");

    Figure figure;

    int count = 0;
    if (!myReadFile)
    {
        return EXIT_FAILURE;
    }
    else
    {
        std::string line;
        while (getline(myReadFile, line))
        {
            std::stringstream ss(line);
            while(ss >> p)
            {
                if (sizeOfArray <= count)
                {
                    sizeOfArray += 1;
                    float *oldArray = array;
                    array = new float[sizeOfArray];
                    for (int i = 0; i < count; i++)
                    {
                        array[i] = oldArray[i];
                    }
                    delete[] oldArray;
                }
                array[count] = p;
                ++count;
            }
            Coordinates *arrayShape = new Coordinates[sizeOfArray / 2];
            for (int i = 0; i < sizeOfArray; i += 2)
            {
                arrayShape[i / 2].x = array[i];
                arrayShape[i / 2].y = array[i + 1];
            }
            Shape &shape = defineShape(arrayShape, sizeOfArray);

            figure.addShape(&shape);
        }
      
        if (count % 2 == 1)
        {
            cout << "File needs an even amount of numbers.\n";
            return EXIT_FAILURE;
        }
    }
    myReadFile.close();
    Box boundingBox = figure.getBoundingBox();

    std::cout << boundingBox;

    return 0;
}

Shape& defineShape(Coordinates *array, int sizeOfArray)
{
    Shape *newShape;
    if(sizeOfArray == 2)
    {
        newShape = new Point(array, sizeOfArray/2);
    }
    else if(sizeOfArray == 4)
    {
        newShape = new Line(array, sizeOfArray/2);
    }
    else if(sizeOfArray == 6)
    {
        newShape = new Triangle(array, sizeOfArray/2);
    }
    else if(sizeOfArray > 6)
    {
        newShape = new Polygon(array, sizeOfArray/2);
    }

    return *newShape;
}

void printType(Shape *shape)
{
    std::cout << "Type is: " << shape->getType() << std::endl;
}
void printPosition(Shape *shape)
{
    Coordinates coordinates = shape->position();
    std::cout << "Center coordinates: (" << coordinates.x << ", " << coordinates.y << ")" << std::endl;
}

void printArea(Shape *shape)
{
    double area = shape->area();

    std::cout << " " << area << std::endl;
}

void printCircumference(Shape *shape)
{
    double circumference = shape->circumference();

    std::cout << "circumference is: " << circumference << std::endl;
}

