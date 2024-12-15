/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Приведение типов между int и float

//Задача 3. Метеостанция

#include <iostream>

int main()
{
    float lowTemp;
    std::cout << "Low temperature limit: ";
    std::cin >> lowTemp;

    float highTemp;
    do 
    {
        std::cout << "High temperature limit: ";
        std::cin >> highTemp;
        if (highTemp <= lowTemp)
            std::cout << "The high temperature limit cannot be less than or equal to the low temperature limit.\n";
    } while (highTemp <= lowTemp);

    float increment;
    std::cout << "Increment: ";
    std::cin >> increment;

    std::cout << "C\tF\n";

    int currentTemp = lowTemp;
    for (; currentTemp <= highTemp; currentTemp += increment)
    {
        int tempFahr = currentTemp * 1.8 + 32;
        std::cout << currentTemp << "\t" << tempFahr << '\n';
    }
    if (currentTemp != highTemp)
    {
        std::cout << highTemp << "\t" << highTemp * 1.8 + 32 << '\n';
    }
    return 0;
}
