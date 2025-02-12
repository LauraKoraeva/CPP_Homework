#pragma once
#include "phonebook.h"

class Phone
{
    PhoneBook* phoneBook;
    std::string contactName;
    std::string contactNumber;
    
public:
    enum Operation
    {
        ADD = 1,
        CALL,
        SMS,
        EXIT,
    };

    Phone();

    bool checkNumber();

    void add();

    void findContact();

    void call();

    void sms();

    ~Phone();
};