#pragma once
#include "shape.h"

class Triangle : public Shape
{
private:
    double sideA;
    double sideB;
    double sideC;
    
public:
    Triangle(double inSideA, double inSideB, double inSideC);
    
    virtual double calculateSquare();
    
    virtual BoundingBoxDimensions calculateDimensions();
    
    virtual std::string defineType();
};