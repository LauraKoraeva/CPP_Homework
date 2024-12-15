/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Варианты цикла for

//Задача 2. Кадастровые проблемы (цикл for).

#include <iostream>

int main()
{
    std::cout << "Enter the area of the plot: ";
    int area;
    std::cin >> area;

    while (area < 0)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> area;
    }

    int count = 1;
    for (; count * count < area; ++count)
    {
    }

    if (count * count == area)
        std::cout << "The area is a perfect square.\n";
    else
        std::cout << "The area is not a perfect square.\n";

    return 0;
}