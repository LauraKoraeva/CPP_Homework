#include <iostream>
#include "ram.h"
#include "cpu.h"

void compute()
{
    int sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += buffer[i];
    }
    std::cout << "\nThe sum of 8 numbers from RAM: " << sum << "\n\n";
}

