

#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"
#include "utility.h"

int main()
{
    while (true)
    {
        std::cout << "Choose the command:\n";
        std::cout << "1 - input numbers\n";
        std::cout << "2 - display numbers\n";
        std::cout << "3 - add up numbers\n";
        std::cout << "4 - save numbers\n";
        std::cout << "5 - load numbers\n";
        std::cout << "6 - exit\n";
        
        int choice;
        do
        {
            std::cin >> choice;
        } while (!correctInput(choice));

        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            display();
            break;
        case 3:
            compute();
            break;
        case 4:
            save();
            break;
        case 5:
            load();
            break;
        case 6:
            return 0;
        default:
            std::cout << "No such command.\n";
        }
    }

}
