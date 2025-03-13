#include <iostream>
#include <cassert>
#include <cmath>
#include "Circle.h"
//#include "Shape.h"
//#include "BoundingBox.h"

Circle::Circle(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inRadius = 1)
    : Shape(inCentroid_x, inCentroid_y, inColour), radius(inRadius)
{
    assert(inRadius > 0);
    calculateBoundingBoxDimensions();
    calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
}

double Circle::calculateSquare() 
{
    return std::atan(1) * 4 * radius;
}

void Circle::calculateBoundingBoxDimensions() 
{
    boundingBoxLength = radius * 2;
    boundingBoxWidth = boundingBoxLength;
}

void Circle::printParameters()
{
    std::cout << "\n----------------------------------\n";
    std::cout << "---------SHAPE-PARAMETERS---------\n";
    std::cout << "----------------------------------\n";
    std::cout << "Shape: circle\n";
    Shape::printParameters();
    printBoundingBoxInfo();
    std::cout << "----------------------------------\n\n";
}

Circle::~Circle() { }