#pragma once
#include "Shape.h"
#include "BoundingBox.h"

class Circle final : public Shape, public BoundingBox
{
    double radius;

public:
    Circle(double inCentroid_x, double inCentroid_y, int inColour, double inRadius);

    double calculateSquare() override;

    void calculateBoundingBoxDimensions() override;

    void printParameters() override;

    ~Circle() override;
};