/*Массивы и Указатели в C++
Урок 1. Одномерные массивы. Базовые алгоритмы на массивах*/

//Задание 4. Ряд чисел*

#include <iostream>

int main()
{
    int arr[15] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 11 };
    int length = 15;

    int sumTotal = 0;
    int min = arr[0];
    for (int index = 0; index < length; ++index)
    {
        if (arr[index] < min)
            min = arr[index];

        sumTotal += arr[index];
    }

    int currentNumber = min;
    int sumNumbers = 0;
    for (int index = 0; index < length - 1; ++index)
    {
        sumNumbers += currentNumber;
        ++currentNumber;
    }

    int repeatedNumber = sumTotal - sumNumbers;

    std::cout << "The starting number in the array: " << min << '\n';
    std::cout << "The repeated number in the array: " << repeatedNumber << '\n';

    return 0;
}
