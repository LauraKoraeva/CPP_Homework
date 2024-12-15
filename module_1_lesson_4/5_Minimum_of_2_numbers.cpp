/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Практическая работа

//Задание 1. Минимум из двух чисел

#include <iostream>

int main()
{
    std::cout << "Let's compare two numbers.\n";
    std::cout << "Enter the first number: ";
    int number1;
    std::cin >> number1;

    std::cout << "Enter the second number: ";
    int number2;
    std::cin >> number2;

    if (number1 < number2)
    {
        std::cout << "The minimum number: " << number1 << "\n";
    }
    else if (number2 < number1)
    {
        std::cout << "The minimum number: " << number2 << "\n";
    }
    else
    {
        std::cout << "The numbers are equal!\n";
    }

    return 0;
}