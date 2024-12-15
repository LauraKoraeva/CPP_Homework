/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Применение цикла while. Инструкция break

//Задача 4. Военное время.

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    int result = 0;
    while (number != 0)
    {
        result = result * 10 + number % 10;
        number /= 10;
    }
    std::cout << result << '\n';

    return 0;
}