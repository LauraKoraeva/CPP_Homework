/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Практическая работа

//Задание 1. Кукушка

#include <iostream>

int main()
{
    std::cout << "Enter the time: ";
    int hour;
    std::cin >> hour;

    while (hour <= 0 || hour > 12)
    {
        std::cout << "Time must be between 1 and 12. Enter the time: ";
        std::cin >> hour;
    }

    int count = 0;
    while (count < hour)
    {
        std::cout << "Cuckoo!\n";
        ++count;
    }

    return 0;
}
