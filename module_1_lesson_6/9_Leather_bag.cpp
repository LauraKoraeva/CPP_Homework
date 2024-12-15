/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Применение цикла while. Инструкция break

//Задача 3. Кожаный мешок.

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    while (number < 0)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> number;
    }

    bool found = false;
    while (number != 0 && !found)
    {
        found = number % 10 > 1;
        number /= 10;
    }

    if (found)
        std::cout << "The number does not consist only of 0 and 1.\n";
    else
        std::cout << "The number consists only of 0 and 1.\n";
    return 0;
}