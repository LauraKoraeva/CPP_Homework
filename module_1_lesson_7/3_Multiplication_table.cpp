/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Циклы for

//Задача 3. Таблица умножения.

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    for (int count = 1; count <= 10; ++count)
    {
        int result = number * count;
        std::cout << number << " * " << count << " = " << result << '\n';
    }

    return 0;
}