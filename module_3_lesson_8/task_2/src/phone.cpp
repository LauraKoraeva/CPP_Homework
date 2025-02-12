#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <numeric>
#include "phone.h"
#include "phonebook.h"
#include "utility.h"

Phone::Phone()
    {
        contactName = "Unknown";
        contactNumber = "Unknown";
        phoneBook = new PhoneBook;
    }

bool Phone::checkNumber()
{
    std::string code = "+7 ";
    if (contactNumber.size() != 13 || contactNumber.compare(0, 3, code))
        return false;
    else
        return true;
}

void Phone::add()
{
    std::cout << "Enter name: ";
    std::getline(std::cin, contactName);

    std::cout << "Enter number: ";
    std::getline(std::cin, contactNumber);
    if (!checkNumber())
    {
        std::cerr << "Invalid phone number.\n";
    }

    phoneBook->setContact(contactName, contactNumber);
}

void Phone::findContact()
{
    std::cout << "1 - search by name\n";
    std::cout << "2 - search by number\n";
    int choice;
    do
    {
        std::cout << "Do you want to search by number or by name: ";
        std::cin >> choice;
    } while (!correctInput(choice));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 1)
    {
        std::cout << "Enter name: ";
        std::getline(std::cin, contactName);
        contactNumber = phoneBook->getNumber(contactName);
    }
    else if (choice == 2)
    {
        std::cout << "Enter number: ";
        std::getline(std::cin, contactNumber);
        contactName = phoneBook->getName(contactNumber);
    }
}

void Phone::call()
{
    findContact();
    std::cout << "\n********************\n";
    std::cout << contactName << '\n';
    std::cout << contactNumber << '\n';
    std::cout << "********************\n";
    std::cout << "CALLING...\n";
}

void Phone::sms()
{
    findContact();
    std::cout << "\n********************\n";
    std::cout << contactName << '\n';
    std::cout << contactNumber << '\n';
    std::cout << "********************\n";
    std::cout << "Message: ";
    std::string text;
    std::getline(std::cin, text);
}

Phone::~Phone()
{
    delete phoneBook;
}