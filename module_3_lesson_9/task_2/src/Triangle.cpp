#include <iostream>
#include <cassert>
#include <cmath>
#include "Triangle.h"

Triangle::Triangle(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inSideLength = 1)
    : Shape(inCentroid_x, inCentroid_y, inColour), sideLength(inSideLength)
{
    assert(inSideLength > 0);
    calculateBoundingBoxDimensions();
    calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
}

double Triangle::calculateSquare() 
{
    return sideLength * sideLength * std::sqrt(3) / 4;
}

void Triangle::calculateBoundingBoxDimensions() 
{
    boundingBoxLength = (std::pow(sideLength, 3) / (4 * calculateSquare())) * 2;
    boundingBoxWidth = boundingBoxLength;
}

void Triangle::printParameters() 
{
    std::cout << "\n----------------------------------\n";
    std::cout << "---------SHAPE-PARAMETERS---------\n";
    std::cout << "----------------------------------\n";
    std::cout << "Shape: triangle\n";
    Shape::printParameters();
    printBoundingBoxInfo();
    std::cout << "----------------------------------\n\n";
}

Triangle::~Triangle() { }