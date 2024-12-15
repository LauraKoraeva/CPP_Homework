/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Применение цикла while. Инструкция break

//Задача 1. Банкомат 4.0.

#include <iostream>

int main()
{
    std::cout << "Enter the PIN code: ";
    int pinCode;
    std::cin >> pinCode;
    int sum = 0;
    int lastDigit;

    while (pinCode != 0)
    {
        lastDigit = pinCode % 10;
        sum += lastDigit;
        pinCode /= 10;
    }

    if (sum == 42)
        std::cout << "Correct input.\n";
    else
        std::cout << "Incorrect input.\n";

    return 0;
}