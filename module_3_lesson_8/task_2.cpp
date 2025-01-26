#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

class PhoneBook
{
    std::string m_name;
    std::string m_number;

    std::multimap<std::string, std::string> nameNumber;
    std::multimap<std::string, std::string> numberName;

public:
    void setContact(std::string name, std::string number)
    {
        m_name = name;
        m_number = number;
        nameNumber.emplace(m_name, m_number);
        numberName.emplace(m_number, m_name);
    }

    std::string getNumber(std::string name)
    {
        if (!nameNumber.empty())
        {
            if (nameNumber.find(name) != nameNumber.end())
            {
                std::string number = nameNumber.find(name)->second;
                return number;
            }
            else
                std::cout << "Could not find the name\n";
        }
        else
            std::cout << "Phonebook is empty.\n";
    }

    std::string getName(std::string number)
    {
        if (!numberName.empty())
        {
            if (numberName.find(number) != numberName.end())
            {
                std::string name = numberName.find(number)->second;
                return name;
            }
            else
                std::cout << "Could not find the number.\n";
        }
        else
            std::cout << "Phonebook is empty.\n";
    }
};

class Phone
{
    PhoneBook phoneBook;
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

    bool checkNumber()
    {
        std::string code = "+7 ";
        if (contactNumber.size() != 13 || contactNumber.compare(0, 3, code))
            return false;
        else
            return true;
    }
    
    int add()
    {
        std::cout << "Enter name: ";
        std::getline(std::cin, contactName);
        
        std::cout << "Enter number: ";
        std::getline(std::cin, contactNumber);
        if (!checkNumber())
        {
            std::cerr << "Invalid phone number.\n";
        }
        
        phoneBook.setContact(contactName, contactNumber);
    }

    void findContact()
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
            contactNumber = phoneBook.getNumber(contactName);
        }
        else if (choice == 2)
        {
            std::cout << "Enter number: ";
            std::getline(std::cin, contactNumber);
            contactName = phoneBook.getName(contactNumber);
        }
    }

    void call()
    {
        findContact();
        std::cout << "\n********************\n";
        std::cout << contactName << '\n';
        std::cout << contactNumber << '\n';
        std::cout << "********************\n";
        std::cout << "CALLING...\n";
    }

    void sms()
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
};

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