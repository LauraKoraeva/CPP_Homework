#include <iostream>
#include "coordinates.h"

void scalpel(const Point& cutPoint_1, const Point& cutPoint_2)
{
    std::cout << "\nA cut was made between ";
    printPoint(cutPoint_1);
    std::cout << " and ";
    printPoint(cutPoint_2);
    std::cout << '\n';
}

void hemostat(const Point& point)
{
    std::cout << "\nHemostat was used at ";
    printPoint(point);
    std::cout << '\n';
}

void tweezers(const Point& point)
{
    std::cout << "\nA clamp was made at ";
    printPoint(point);
    std::cout << '\n';
}

void suture(const Point& point_1, const Point& point_2)
{
    std::cout << "\nStitches were made at ";
    printPoint(point_1);
    std::cout << " and ";
    printPoint(point_2);
    std::cout << '\n';
}