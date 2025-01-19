// Продвинутые темы и техники C++
// Урок 4. Словари std::map

//Задание 1. Телефонный справочник

#include <iostream> 
#include <map>
#include <string>
#include <vector>
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

void addPhone(std::map<std::string, std::string>& numberSurname, std::map<std::string, std::vector<std::string>>& surnameNumber)
{
    std::string phoneNumber;
    std::string surname;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    numberSurname.insert(std::pair<std::string, std::string>(phoneNumber, surname));
    surnameNumber[surname].push_back(phoneNumber);
}

void findName(std::map<std::string, std::string>& numberSurname)
{
    std::string phoneNumber;
    std::cout << "Enter phone number:";
    std::getline(std::cin, phoneNumber);

    std::map<std::string, std::string>::iterator it = numberSurname.find(phoneNumber);
    if
        (it == numberSurname.end()) std::cout << "Not found" << '\n';
    else
        std::cout << "Phone number belongs to: " << it->second << '\n';
}

void findPhone(std::map<std::string, std::vector<std::string>>& surnameNumber)
{
    std::string surname;
    std::cout << "Enter surname: ";
    std::getline(std::cin, surname);

    std::map<std::string, std::vector<std::string>>::iterator it = surnameNumber.find(surname);
    if (it == surnameNumber.end())
        std::cout << "Not found" << '\n';
    else
    {
        for (std::vector<std::string>::iterator itf = it->second.begin();
            itf != it->second.end(); ++itf)
        {
            std::cout << *itf << " ";
        }
    }
}

int main()
{
    std::map<std::string, std::string> numberSurname;
    numberSurname["8-945-135-10-74"] = "Ivanov";
    numberSurname["8-906-547-35-36"] = "Ivanov";
    numberSurname["8-906-156-97-00"] = "Petrov";
    numberSurname["8-945-237-82-15"] = "Popov";

    std::map<std::string, std::vector<std::string>> surnameNumber
    {
            {"Ivanov", {"8-945-135-10-74", "8-906-547-35-36"}},
            {"Petrov", {"8-906-156-97-00"}},
            {"Popov", {"8-945-237-82-15"}}
    };

    std::cout << "1 - Add phone number and surname to phone directory;" << '\n';
    std::cout << "2 - Find name by phone number;" << '\n';
    std::cout << "3 - find phone by name: " << '\n';
    std::cout << "Select the operation: ";
    int operation;
    do
    {
        std::cin >> operation;
    } while (!correctInput(operation));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (operation == 1)
        addPhone(numberSurname, surnameNumber);
    else if (operation == 2)
        findName(numberSurname);
    else if (operation == 3)
        findPhone(surnameNumber);

    return 0;
}
