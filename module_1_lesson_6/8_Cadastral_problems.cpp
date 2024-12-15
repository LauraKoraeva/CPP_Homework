/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Применение цикла while. Инструкция break

//Задача 2. Кадастровые проблемы.

#include <iostream>

int main()
{
    std::cout << "Enter the area of the plot: ";
    int area;
    std::cin >> area;

    while (area <= 0 || area > 1000000)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> area;
    }

    int count = 1;
    while (area * count < area)
        ++count;

    if (count * count == area)
        std::cout << "The area is a perfect square.\n";
    else
        std::cout << "The area is not a perfect square.\n";

    return 0;
}