#include <iostream>
#include <string>
#include <limits>
#include <numeric>
#include "animals.h"
#include "utility.h"

enum Operation
{
    CHOOSE_TALENT = 1,
    SHOW_TALENTS,
    EXIT,
};

int main()
{
    std::cout << "Enter the name of your pet: ";
    std::string name;
    std::getline(std::cin, name);
    Dog dog(name);
    
    int choice;

    while (true)
    {
        std::cout << "------------------------------\n";
        std::cout << "Choose the next operation:\n";
        std::cout << "1 - choose talent\n";
        std::cout << "2 - show talents\n";
        std::cout << "3 - exit\n";
        std::cout << "------------------------------\n";
        do
        {
            std::cin >> choice;
        } while (!correctInput(choice));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case CHOOSE_TALENT:
            dog.add_talent();
            break;
        case SHOW_TALENTS:
            dog.show_talents();
            return 0;
        case EXIT:
            return 0;
        default:
            std::cout << "No such operation.\n";
        }
    }
}