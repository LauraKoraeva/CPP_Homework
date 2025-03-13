#pragma once
#include "Shape.h"
#include "BoundingBox.h"

class Square final : public Shape, public BoundingBox
{
    double sideLength;

public:
    Square(double inCentroid_x, double inCentroid_y, int inColour, double inSideLength);

    double calculateSquare() override;

    void calculateBoundingBoxDimensions() override;

    void printParameters() override;

    ~Square() override;
};