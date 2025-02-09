#include <iostream>
#include <fstream>
#include "ram.h"
#include "disk.h"

void save()
{
    std::ofstream out_data("data.txt");
    if (out_data.is_open())
    {
        for (int i = 0; i < 8; ++i)
        {
            out_data << buffer[i] << " ";
        }
        out_data.close();
        std::cout << "\nData has been saved.\n\n";
    }
    else
        std::cout << "\nInvalid path.\n\n";     
}

void load()
{
    std::ifstream in_data;
    in_data.open("data.txt");
    if (in_data.is_open())
    {
        for (int i = 0; i < 8; ++i)
        {
            in_data >> buffer[i];
        }
        in_data.close();
        std::cout << "\nData has been loaded to RAM.\n\n";
    }
    else
        std::cout << "\nInvalid path.\n\n";   
}
