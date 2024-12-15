/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Варианты цикла for

//Задача 1. Пароль (цикл for).

#include <iostream>

int main()
{
    bool result = false;
    for (; !result; )
    {
        std::cout << "Enter the password: ";
        int password;
        std::cin >> password;

        int sum = 0;
        for (; password != 0; password /= 10)
        {
            sum += password % 10;
        }

        if (sum == 42)
            result = true;           
        else
            std::cout << "The password is incorrect.\n";
    }
    std::cout << "The password is correct.";

    return 0;
}