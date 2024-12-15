/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Приведение типов между int и float

//Задача 4. Аккуратность

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
            std::cout << "Incorrect input. Try again!";
        else correctInput = true;
    } while (!correctInput);

    int position_x = x * 10;
    int position_y = y * 10;

    double adjust_x, adjust_y;
   
    adjust_x = 0.050 - (x - (double) position_x / 10);
    adjust_y = 0.050 - (y - (double) position_y / 10);
    
   std::cout << "Chess piece is on square (" << position_x << ", " << position_y << ").\n"; 
   std::cout << "Adjust the position of the piece by (" << adjust_x << ", " << adjust_y << ").\n";

    return 0;
}
