/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while

//Задача 6. Сумма чисел.

#include <iostream>

int main()
{
    std::cout << "How many numbers do you want to add up: ";
    int numbersCount;
    std::cin >> numbersCount;
    int inputCounts = 1;
    int sum = 0;
    while (inputCounts <= numbersCount)
    {
        std::cout << "Enter number " << inputCounts << ": ";
        int number;
        std::cin >> number;
        sum += number;
        ++inputCounts;
    }
    std::cout << "The sum of the entered numbers: " << sum << '\n';

    return 0;
}