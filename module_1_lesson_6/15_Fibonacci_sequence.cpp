/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Практическая работа

//Задание 5. Числа Фибоначчи

#include <iostream>

int main()
{
    std::cout << "Enter the number of the number from the Fibonacci sequence: ";
    int number;
    std::cin >> number;

    int number_1 = 1;
    int number_2 = 1;
    int currentNumber = 0;

    if (number <= 0 || number > 46)
        std::cout << "The number cannot be negative, or equal to zero, or greater than 46.";
    else if (number == 1 || number == 2)
    {
        std::cout << number_1;
    }

    else
    {
        int count = 3;
        while (count <= number)
        {
            currentNumber = number_1 + number_2;

            number_1 = number_2;
            number_2 = currentNumber;
            ++count;
        }
        std::cout << currentNumber << '\n';
    }

    return 0;
}
