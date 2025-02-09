#include <iostream>
#include "ram.h"
#include "kbd.h"

void input()
{

    std::cout << "\nEnter 8 integers:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> buffer[i];
    }
    std::cout << '\n';
}