#include <iostream>
#include <cassert>
#include "Square.h"

Square::Square(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inSideLength = 1)
    : Shape(inCentroid_x, inCentroid_y, inColour), sideLength(inSideLength)
{
    assert(inSideLength > 0);
    calculateBoundingBoxDimensions();
    calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
}

double Square::calculateSquare() 
{
    return sideLength * sideLength;
}

void Square::calculateBoundingBoxDimensions() 
{
    boundingBoxLength = sideLength;
    boundingBoxWidth = sideLength;
}

void Square::printParameters() 
{
    std::cout << "\n----------------------------------\n";
    std::cout << "---------SHAPE-PARAMETERS---------\n";
    std::cout << "----------------------------------\n";
    std::cout << "Shape: square\n";
    Shape::printParameters();
    printBoundingBoxInfo();
    std::cout << "----------------------------------\n\n";
}

Square::~Square() { }