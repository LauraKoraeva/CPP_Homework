#pragma once
#include "shape.h"

class Circle : public Shape
{
private:
    double radius;
    
public:
    Circle(double inRadius);
    
    virtual double calculateSquare();
    
    virtual BoundingBoxDimensions calculateDimensions();
    
    virtual std::string defineType();

    ~Circle();
};
