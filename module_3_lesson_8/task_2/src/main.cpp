#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <numeric>
#include "phone.h"
#include "utility.h"

int main()
{
    Phone* operation = new Phone;

    int choice;
    std::cout << "1 - add new contact\n";
    std::cout << "2 - make a call\n";
    std::cout << "3 - sent sms\n";
    std::cout << "4 - exit\n";

    while (true)
    {
        do
        {
            std::cout << "\nChoose the operation: ";
            std::cin >> choice;
        } while (!correctInput(choice));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << '\n';

        switch (choice)
        {
        case operation->ADD:
            operation->add();
            break;
        case operation->CALL:
            operation->call();
            break;
        case operation->SMS:
            operation->sms();
            break;
        case operation->EXIT:
            delete operation;
            return 0;
        default:
            std::cout << "No such operation.\n";

        }
    }
}