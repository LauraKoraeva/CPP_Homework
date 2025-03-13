#include <iostream>
#include "WorkType.h"

void printWorkType(int type)
{
    switch (type)
    {
    case A:
        std::cout << "A";
        break;
    case B:
        std::cout << "B";
        break;
    case C:
        std::cout << "C";
        break;
    }
}