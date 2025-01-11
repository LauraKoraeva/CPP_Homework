// Продвинутые темы и техники C++
// Урок 1. Чтение из файлов

// Задание 3. Реализация программы чтения ведомости

#include <iostream>
#include <string>
#include <fstream>

struct EmployeeInfo
{
    std::string name;
    std::string surname;
    int cash;
    std::string date;
};

int main()
{
    std::ifstream data;
    data.open("info.txt", std::ios::binary);

    if (data.is_open())
    {
        int sum = 0;
        int maxCash = 0;
        std::string maxName;
        std::string maxSurname;
        std::string maxDate;

        while (!data.eof())
        {
            EmployeeInfo employee;
            data >> employee.name >> employee.surname >> employee.cash >> employee.date;

            sum += employee.cash;
            if (employee.cash > maxCash)
            {
                maxCash = employee.cash;
                maxName = employee.name;
                maxSurname = employee.surname;
                maxDate = employee.date;
            }
        }
        std::cout << "Total cash: " << sum << '\n';
        std::cout << "Max cash " << "(" << maxCash << ") was paid to " << maxName << " " << maxSurname << " on " << maxDate << '\n';

        data.close();
    }
    else
        std::cout << "Path is not valid.\n";

    return 0;
}