/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Тип данных float

//Задача 1. Орехи

#include <iostream>

int main()
{
    std::cout << "Enter the price of the product per 100 grams: ";
    float fixedPrice;
    std::cin >> fixedPrice;

    while (fixedPrice <= 0)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> fixedPrice;
    }

    std::cout << "Enter the purchase weight: ";
    float productAmount;
    std::cin >> productAmount;

    while (productAmount <= 0)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> productAmount;
    }

    float finalCost = fixedPrice / 100 * productAmount;
    std::cout << "Purchase price: " << finalCost;

    return 0;
}