#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(double inLength, double inWidth)
{
    if (inLength <= 0 || inWidth <= 0)
        std::cout << "Incorrect input\n";
    else
    {
        length = inLength;
        width = inWidth;
    }
}

double Rectangle::calculateSquare()
{
    double square = length * width;
    return square;
}

Shape::BoundingBoxDimensions Rectangle::calculateDimensions()
{
    BoundingBoxDimensions dimensions;
    dimensions.height = length;
    dimensions.width = width;
    return dimensions;
}

std::string Rectangle::defineType()
{
    return "Rectangle";
}