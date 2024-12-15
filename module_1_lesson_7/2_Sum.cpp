/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Циклы for

//Задача 2. Сумма чисел (цикл for).

#include <iostream>

int main()
{
    std::cout << "How many numbers do you want to add up: ";
    int numbersCount;
    std::cin >> numbersCount;
    
    int sum = 0;
    for (int inputCounts = 1; inputCounts <= numbersCount; ++inputCounts)
    {
        std::cout << "Enter number " << inputCounts << ": ";
        int number;
        std::cin >> number;
        sum += number;
    }

    std::cout << "The sum of the entered numbers: " << sum << '\n';

    return 0;
}