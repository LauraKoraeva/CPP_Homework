/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while

//Задача 3. Таблица степеней.

#include <iostream>

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "How many times to multiply? ";
    int resultCount;
    std::cin >> resultCount;

    int result = number;
    std::cout << result * 1 << ", ";

    int count = 0;
    while (count < resultCount)
    {
        result *= number;
        if (count == resultCount - 1)
            std::cout << result;
        else
            std::cout << result << ", ";
        ++count;
    }

    return 0;
}