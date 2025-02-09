#pragma once

struct Point
{
    double x = 0;
    double y = 0;
};

void getPoint(Point& point);

void printPoint(const Point& point);

bool areEqual(const Point& point_1, const Point& point_2);