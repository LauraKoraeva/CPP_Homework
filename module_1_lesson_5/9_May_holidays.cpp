/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Практическая работа

//Задание 2. Майские

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
        if (date % 7 == 0 || (date + 1) % 7 == 0)
        {
            std::cout << "Weekend!";
        }
        else
            std::cout << "Working day!";
    return 0;
}