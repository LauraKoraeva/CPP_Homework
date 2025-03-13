#pragma once
#include "Shape.h"
#include "BoundingBox.h"

class Rectangle final : public Shape, public BoundingBox
{
    double length;
    double width;

public:
    Rectangle(double inCentroid_x, double inCentroid_y, int inColour, double inLength, double inWidth);

    double calculateSquare() override;

    void calculateBoundingBoxDimensions() override;

    void printParameters() override;

    ~Rectangle() override;
};