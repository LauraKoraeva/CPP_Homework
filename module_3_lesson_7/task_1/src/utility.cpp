#include <iostream>
#include <limits>
#include <numeric>
#include "utility.h"

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input < 0)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}