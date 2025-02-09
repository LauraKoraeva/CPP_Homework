#include <iostream>
#include "coordinates.h"
#include "instruments.h"

int main()
{
    Point cutPoint_1;
    Point cutPoint_2;
    Point point_3;
    Point point_4;
    std::cout << "Specify the location of the incision.\n";
    std::cout << "Beginning:\n";
    getPoint(cutPoint_1);
    std::cout << "End:\n";
    getPoint(cutPoint_2);

    scalpel(cutPoint_1, cutPoint_2);

    int choice;
    while (true)
    {
        std::cout << "\nChoose the next procedure:\n";
        std::cout << "1 - hemostat\n";
        std::cout << "2 - tweezers\n";
        std::cout << "3 - suture\n";
        std::cout << '\n';
        std::cin >> choice;        //

        switch (choice)
        {
        case 1:
            std::cout << "Enter the location.\n";
            getPoint(point_3);
            hemostat(point_3);
            break;
        case 2:
            std::cout << "Enter the location.\n";
            getPoint(point_3);
            tweezers(point_3);
            break;
        case 3:
            do
            {
                std::cout << "Enter the location for the stitching.\n";
                getPoint(point_3);
                getPoint(point_4);
            } while (!areEqual(cutPoint_1, point_3) || !areEqual(cutPoint_2, point_4));

            suture(point_3, point_4);
            std::cout << "\nThe operation was completed successfully!\n";
            return 0;
        }
    }
}
