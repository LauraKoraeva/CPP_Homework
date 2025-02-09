#include <iostream>
#include "ram.h"
#include "gpu.h"

void display()
{
    std::cout << "\nContents of RAM:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << "\n\n";
}