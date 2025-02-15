#include <iostream>
#include <cmath>
#include "circle.h"

Circle::Circle(double inRadius)
{
    if (inRadius <= 0)
        std::cout << "Incorrect input.\n";
    else
        radius = inRadius;
}

double Circle::calculateSquare()
{
    const double pi = 3.14159;
    double square = pi * (pow(radius, 2));
    return square;
}

Shape::BoundingBoxDimensions Circle::calculateDimensions()
{
    BoundingBoxDimensions dimensions;
    dimensions.height = radius * 2;
    dimensions.width = dimensions.height;
    return dimensions;
}

std::string Circle::defineType()
{
    return "Circle";
}
