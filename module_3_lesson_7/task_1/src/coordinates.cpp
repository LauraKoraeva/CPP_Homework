#include <iostream>
#include "coordinates.h"

void getPoint(Point& point)
{
    std::cout << "x: ";
    std::cin >> point.x;
    std::cout << "y: ";
    std::cin >> point.y;
}

void printPoint(const Point& point)
{
    std::cout << "(" << point.x << "; " << point.y << ")";
}

bool areEqual(const Point& point_1, const Point& point_2)
{
    if (point_1.x != point_2.x || point_1.y != point_2.y)
    {
        std::cout << "The location for the stitching is wrong.\n";
        return false;
    }
    else
        return true;
}