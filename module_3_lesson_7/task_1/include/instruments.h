#pragma once
#include "coordinates.h"

void scalpel(const Point& cutPoint_1, const Point& cutPoint_2);

void hemostat(const Point& point);

void tweezers(const Point& point);

void suture(const Point& point_1, const Point& point_2);