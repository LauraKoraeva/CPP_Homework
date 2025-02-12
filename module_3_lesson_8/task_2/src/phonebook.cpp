#include <iostream>
#include <string>
#include <map>
#include "phonebook.h"


void PhoneBook::setContact(std::string inName, std::string inNumber)
{
    name = inName;
    number = inNumber;
    nameNumber.emplace(name, number);
    numberName.emplace(number, name);
}

std::string PhoneBook::getNumber(std::string inName)
{
    if (!nameNumber.empty())
    {
        if (nameNumber.find(inName) != nameNumber.end())
        {
            std::string number = nameNumber.find(inName)->second;
            return number;
        }
        else
            std::cout << "Could not find the name\n";
    }
    else
        std::cout << "Phonebook is empty.\n";
}

std::string PhoneBook::getName(std::string inNumber)
{
    if (!numberName.empty())
    {
        if (numberName.find(inNumber) != numberName.end())
        {
            std::string name = numberName.find(inNumber)->second;
            return name;
        }
        else
            std::cout << "Could not find the number.\n";
    }
    else
        std::cout << "Phonebook is empty.\n";
}