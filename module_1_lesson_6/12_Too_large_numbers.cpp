/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Практическая работа

//Задание 2. Слишком большие числа

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;
    int count = 0;
    if (number != 0)
    {
        while (number != 0)
        {
            number /= 10;
            ++count;
        }
    }
    else
        count = 1;
    std::cout << "Digits in the number: " << count << '\n';

    return 0;
}