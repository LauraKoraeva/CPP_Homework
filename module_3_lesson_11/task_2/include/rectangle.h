#pragma once
#include "shape.h"

class Rectangle : public Shape
{
private:
    double length;
    double width;
    
public:
    Rectangle(double inLength, double inWidth);
    
    virtual double calculateSquare();
    
    virtual BoundingBoxDimensions calculateDimensions();
    
    virtual std::string defineType();

    ~Rectangle();
};