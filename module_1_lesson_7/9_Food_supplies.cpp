/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Практическая работа

//Задание 1. Запасы продовольствия

#include <iostream>

int main()
{
    int buckwheat = 100;
    std::cout << "At the beginning you had " << buckwheat << " kg of buckwheat.\n";

    for (int count = 1; buckwheat > 0; ++count)
    {
        buckwheat -= 4;
        if (buckwheat <= 0)
            std::cout << "After month " << count << " you will have no buckwheat left.\n";
        else
            std::cout << "After month " << count << " you will have " << buckwheat << " kg of buckwheat left.\n";
    }

    return 0;
}