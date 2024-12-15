/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Приведение типов между int и float

//Задача 2. Компьютерное зрение

#include <iostream>

int main()
{
    double x, y;
    bool correctInput = false;
    do
    {
        std::cout << "Enter the coordinates of the chess piece: \n";
        std::cin >> x >> y;
        if (x > 0.799 || x < 0 || y > 0.799 || y < 0)
            std::cout << "Incorrect input. Try again!\n";
        else correctInput = true;
    } while (!correctInput);

    x *= 10;
    y *= 10;

    std::cout << "Chess piece is on square (" << (int)x << ", " << (int)y << ").\n";

    return 0;
}