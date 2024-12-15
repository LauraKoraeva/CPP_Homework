/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Приведение типов между int и float

//Задача 1. Ку!

#include <iostream>

int main()
{
    float kts = 4400.0f;
    float gravitsapa = kts / 2;

    std::cout << "Enter the amount of chatls: ";
    float chatlNumber;
    std::cin >> chatlNumber;
   
    while ((int) chatlNumber - chatlNumber != 0 || chatlNumber < 0)
    {
        std::cout << "Incorrect input. Try again!\n";
        std::cin >> chatlNumber;
    }

    float ktsNumber = chatlNumber / kts;

    int gravitsapaCount = chatlNumber / gravitsapa;

    std::cout << chatlNumber << " ch = " << ktsNumber << " KTS\n";
    std::cout << "The number of gravitsapas you can buy: " << gravitsapaCount;

return 0;

}
