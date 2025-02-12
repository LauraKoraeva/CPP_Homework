#pragma once

class PhoneBook
{
    std::string name;
    std::string number;

    std::multimap<std::string, std::string> nameNumber;
    std::multimap<std::string, std::string> numberName;

public:

    void setContact(std::string inName, std::string inNumber);

    std::string getNumber(std::string inName);

    std::string getName(std::string inNumber);
};