#include <iostream>
#include <iomanip>
#include <cassert>
#include "Shape.h"
#include "Colours.h"


Shape::Shape(double inCentroid_x = 0.0, double inCentroid_y = 0.0, int inColour = 4)
    : centroid_x(inCentroid_x), centroid_y(inCentroid_y), colour(inColour) 
{
    assert(inColour >= 1 && inColour <= 4 && "colour option does not exist");
}

//double Shape::calculateSquare();

void Shape::printParameters()
{
    std::cout << std::setprecision(2);
    std::cout << "Centroid: (" << centroid_x << ", " << centroid_y << ")\n";
    std::cout << "Area: " << calculateSquare() << '\n';
    printColour(colour);
}

Shape::~Shape() { }