/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Практическая работа

//Задание 3. Майские — усложнение

#include <iostream>

int main()
{
    std::cout << "Enter date: ";
    int date;
    std::cin >> date;

    while (date < 1 || date > 31)
    {
        std::cout << "Error! try again.\n";
        std::cin >> date;
    }

    if (date >= 1 && date <= 5 || date >= 8 && date <= 10)
        std::cout << "Weekend!";
    else
    {
        std::cout << "Enter day of the week number: ";
        int weekDay;
        std::cin >> weekDay;

        while (weekDay < 1 || weekDay > 7)
        {
            std::cout << "Error! try again.\n";
            std::cin >> weekDay;
        }

        int diff;
        if (weekDay == 1)
            diff = 0;
        else
            diff = weekDay - 1;

        if ((date + diff) % 7 == 0 || (date + diff + 1) % 7 == 0)
        {
            std::cout << "Weekend!";
        }
        else
            std::cout << "Working day!";
    }
    return 0;
}
