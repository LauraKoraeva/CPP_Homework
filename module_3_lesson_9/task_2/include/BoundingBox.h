#pragma once

class BoundingBox
{
protected:
    double a_x = -1;
    double a_y = 1;
    double b_x = 1;
    double b_y = 1;
    double c_x = -1;
    double c_y = -1;
    double d_x = 1;
    double d_y = -1;
    double boundingBoxLength = 1;
    double boundingBoxWidth = 1;

public:
    BoundingBox();

    virtual void calculateBoundingBoxDimensions() = 0;

    void calculateBoundingBoxCoordinates(double inCentroid_x, double inCentroid_y);

    void printBoundingBoxInfo() const;

    virtual ~BoundingBox();
};