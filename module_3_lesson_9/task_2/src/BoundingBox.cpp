#include <iostream>
#include "BoundingBox.h"

BoundingBox::BoundingBox() { }

//void BoundingBox::calculateBoundingBoxDimensions();

void BoundingBox::calculateBoundingBoxCoordinates(double inCentroid_x, double inCentroid_y)
{
    a_x = inCentroid_x - boundingBoxLength / 2;
    a_y = inCentroid_y + boundingBoxWidth / 2;
    b_x = inCentroid_x + boundingBoxLength / 2;
    b_y = inCentroid_y + boundingBoxWidth / 2;
    c_x = inCentroid_x - boundingBoxLength / 2;
    c_y = inCentroid_y - boundingBoxWidth / 2;
    d_x = inCentroid_x + boundingBoxLength / 2;
    d_y = inCentroid_y - boundingBoxWidth / 2;
}

void BoundingBox::printBoundingBoxInfo() const
{
    std::cout << "Bounding box length: " << boundingBoxLength << '\n';
    std::cout << "Bounding box width: " << boundingBoxWidth << '\n';
    std::cout << "Bounding box coordinates:\n";
    std::cout << "(" << a_x << ", " << a_y << "), (" << b_x << ", " << b_y << "), " <<
        "(" << c_x << ", " << c_y << "), (" << d_x << ", " << d_y << ")\n";
}

BoundingBox::~BoundingBox() { }