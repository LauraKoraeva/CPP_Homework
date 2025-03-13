#pragma once

class Shape
{
protected:
    double centroid_x;
    double centroid_y;
    int colour;

public:
    Shape(double inCentroid_x, double inCentroid_y, int inColour);

    virtual double calculateSquare() = 0;

    virtual void printParameters();

    virtual ~Shape();
};