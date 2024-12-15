/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Практическая работа

//Задание 3. Красный Марс

#include <iostream>
#include <string>

int main() 
{
    int y = 20;
    int x = 15;
    int currentY = 19;
    int currentX = 6;

    while(true)
    {
        std::cout << "The rover is in position " << currentX << ", " << currentY << ", enter the command:\n";
        std::string way;
        std::cin >> way;

        if (way == "A")
        {
            if (currentX > 1)
            {
                currentX -= 1;
            }
        }

        else if (way == "D")
        {
            if (currentX < x)
            {
                currentX += 1;
            }
        }

        else if (way == "S")
        {
            if (currentY > 1)
            {
                currentY -= 1;
            }
        }

        else if (way == "W")
        {
            if (currentY < y)
            {
                currentY += 1;
            }
        }

        else
            std::cout << "Input error. Repeat the direction.\n";


    }
    
    return 0;
}