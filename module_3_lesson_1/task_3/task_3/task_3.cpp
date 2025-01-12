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
        EmployeeInfo max;

        while (!data.eof())
        {
            EmployeeInfo employee;
            data >> employee.name >> employee.surname >> employee.cash >> employee.date;

            sum += employee.cash;
            if (employee.cash > max.cash)
            {
                max = { employee.name, employee.surname, employee.cash, employee.date };
            }
        }
        std::cout << "Total cash: " << sum << '\n';
        std::cout << "Max cash " << "(" << max.cash << ") was paid to " << max.name << " " << max.surname << " on " << max.date << '\n';

        data.close();
    }
    else
        std::cout << "Path is not valid.\n";

    return 0;
}