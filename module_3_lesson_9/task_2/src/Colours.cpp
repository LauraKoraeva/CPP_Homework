#include <iostream>
#include "colours.h"

void printColour(int colourIndex)
{
    switch (colourIndex)
    {
    case RED:
        std::cout << "Colour: red\n";
        break;
    case GREEN:
        std::cout << "Colour: green\n";
        break;
    case BLUE:
        std::cout << "Colour: blue\n";
        break;
    case NONE:
        std::cout << "Colour: none\n";
        break;
    default:
        std::cout << "Colour: unknown\n";
        break;
    }
}