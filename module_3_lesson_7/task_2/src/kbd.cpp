#include <iostream>
#include "ram.h"
#include "kbd.h"
#include "utility.h"

void input()
{

    std::cout << "\nEnter 8 integers:\n";
    for (int i = 0; i < 8; ++i)
    {
        do
        {
            std::cin >> buffer[i];
        } while (!correctInput(buffer[i]));
    }
    std::cout << '\n';
}