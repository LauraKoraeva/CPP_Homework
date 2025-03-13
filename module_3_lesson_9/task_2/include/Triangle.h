#pragma once
#include "Shape.h"
#include "BoundingBox.h"

class Triangle final : public Shape, public BoundingBox
{
    double sideLength;

public:
    Triangle(double inCentroid_x, double inCentroid_y, int inColour, double inSideLength);

    double calculateSquare() override;

    void calculateBoundingBoxDimensions() override;

    void printParameters() override;

    ~Triangle() override;
};