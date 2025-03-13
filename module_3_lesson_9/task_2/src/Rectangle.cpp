#include <iostream>
#include <cassert>
#include "Rectangle.h"

Rectangle::Rectangle(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inLength = 2, double inWidth = 1)
    : Shape(inCentroid_x, inCentroid_y, inColour), length(inLength), width(inWidth)
{
    assert(inLength > 0 && inWidth > 0);
    calculateBoundingBoxDimensions();
    calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
}

double Rectangle::calculateSquare() 
{
    return length * width;
}

void Rectangle::calculateBoundingBoxDimensions() 
{
    boundingBoxLength = length;
    boundingBoxWidth = width;
}

void Rectangle::printParameters() 
{
    std::cout << "\n----------------------------------\n";
    std::cout << "---------SHAPE-PARAMETERS---------\n";
    std::cout << "----------------------------------\n";
    std::cout << "Shape: rectangle\n";
    Shape::printParameters();
    printBoundingBoxInfo();
    std::cout << "----------------------------------\n\n";
}

Rectangle::~Rectangle() { }