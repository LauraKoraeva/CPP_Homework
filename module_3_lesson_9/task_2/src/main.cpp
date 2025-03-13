#include <iostream>
#include <limits>
#include <numeric>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Utility.h"


void showMenu()
{
    std::cout << "Choose operation:\n";
    std::cout << "1 - create circle\n";
    std::cout << "2 - create triangle\n";
    std::cout << "3 - create square\n";
    std::cout << "4 - create rectangle\n";
    std::cout << "5 - exit\n\n";
}



void requestBasicParameters(double& centroid_x, double& centroid_y, int& colour)
{
    std::cout << "\n==================================\n";
    std::cout << "         Enter parameters         \n";
    std::cout << "==================================\n";
    do
    {
        std::cout << "Colour: ";
        std::cin >> colour;  
    } while (!correctInput(colour));
    do
    {
        std::cout << "Centroid x: ";
        std::cin >> centroid_x;  
    } while (!correctInput(centroid_x));
    do
    {
        std::cout << "Centroid y: ";
        std::cin >> centroid_y;  
    } while (!correctInput(centroid_y));
}



int main()
{
    double centroid_x, centroid_y;
    int colour;
    int choice; 

    while (true)
    {
        do
        {
            showMenu();
            std::cin >> choice;     
        } while (!correctInput(choice));

        if (choice == 1)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double radius;
            do
            {
                std::cout << "Radius: ";
                std::cin >> radius; 
            } while (!correctInput(radius));
            Circle shape(centroid_x, centroid_y, colour, radius);
            shape.printParameters();
        }
        else if (choice == 2)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double length;
            do
            {
                std::cout << "Length of the side: ";
                std::cin >> length;  
            } while (!correctInput(length));
            Triangle shape(centroid_x, centroid_y, colour, length);
            shape.printParameters();
        }
        else if (choice == 3)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double length;
            do
            {
                std::cout << "Length of the side: ";
                std::cin >> length; 
            } while (!correctInput(length));
            Square shape(centroid_x, centroid_y, colour, length);
            shape.printParameters();
        }
        else if (choice == 4)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double length, width;
            do
            {
                std::cout << "Length: ";
                std::cin >> length;
            } while (!correctInput(length));
            do
            {
                std::cout << "Width: ";
                std::cin >> width;  
            } while (!correctInput(width));
            Rectangle shape(centroid_x, centroid_y, colour, length, width);
            shape.printParameters();
        }
        else if (choice == 5)
            break;
        else
            std::cout << "No such operation.\n";
    }

    return 0;
}

