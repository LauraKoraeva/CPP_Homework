/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Практическая работа

//Задание 2. Кофемашина

#include <iostream>

int main()
{
    std::cout << "How much water: ";
    int water;
    std::cin >> water;

    std::cout << "How much milk: ";
    int milk;
    std::cin >> milk;

    int countAmericano = 0;
    int countLatte = 0;

    do
    {
        std::cout << "Choose drink (americano - 1, latte - 2): ";
        int choice;
        std::cin >> choice;

        if (choice < 0 || choice > 2)
            std::cout << "Try again!\n";

        else if (choice == 1)
        {
            if (water < 300)
                std::cout << "Not enough water\n";
            else
            {
                water -= 300;
                ++countAmericano;
                std::cout << "Your drink is ready!\n";
            }
        }

        
        else if (choice == 2)
        {
            if (water < 270)
                std::cout << "Not enough water\n";
            else if (milk < 30)
                std::cout << "Not enough milk\n";
            else
            {
                water -= 270;
                milk -= 30;
                ++countLatte;
                std::cout << "Your drink is ready!\n";
            }
        }
    } while (water >= 300 || water >= 270 && milk >= 30);


    std::cout << "\n*****Report*****\n";
    std::cout << "\nIngredients left:\n";
    std::cout << "Water: " << water << " ml\n";
    std::cout << "Milk: " << milk << " ml\n";
    std::cout << "\nAmericano made: " << countAmericano << '\n';
    std::cout << "Latte made: " << countLatte << '\n';

    return 0;
}
