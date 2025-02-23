#include <iostream>
#include <cmath>
#include "triangle.h"

Triangle::Triangle(double inSideA, double inSideB, double inSideC)
{
    if (inSideA <= 0 || inSideB <= 0 || inSideC <= 0)
        std::cout << "Incorrect input\n";
    else
    {
        sideA = inSideA;
        sideB = inSideB;
        sideC = inSideC;
    }
}

double Triangle::calculateSquare()
{
    double p = (sideA + sideB + sideC) / 2;
    double square = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    return square;
}

Shape::BoundingBoxDimensions Triangle::calculateDimensions()
{
    BoundingBoxDimensions dimensions;
    dimensions.height = (sideA * sideB * sideC / (4 * calculateSquare())) * 2;
    dimensions.width = dimensions.height;
    return dimensions;
}

std::string Triangle::defineType()
{
    return "Triangle";
}

Triangle::~Triangle() { }