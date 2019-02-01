#ifndef FIGURE_H
#define FIGURE_H
#include "Shape.h"

class Box
{
    public:
        Coordinates topLeft;
        Coordinates bottomRight;
        friend std::ostream& operator<<(std::ostream& os, const Box& rhs);
};

class Figure
{
    public:
        Figure();
        void addShape(Shape *s);
        Box getBoundingBox();

        //temporary funcyion
        void printShapes();
    private: 
        Shape** shapes;
        int numOfShapes;
};

#endif