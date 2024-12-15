/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Циклы for

//Задача 4. Сумма нечётных.

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    while (number < 1)
    {
        std::cout << "Error! Enter another number:\n";
        std::cin >> number;
    }

    int sum = 0;
    for (int count = 1; count <= number; ++count)
    {
        if (!(count % 2 == 0))
            sum += count;
    }

    std::cout << "The sum of odd numbers in the range from 1 to " << number << ": " << sum << '\n';

    return 0;
}
