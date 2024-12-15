/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Тип данных float

//Задача 3. Постоянный покупатель

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

    std::cout << "Enter the discount amount: ";
    int discount;
    std::cin >> discount;

    while (discount < 0)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> discount;
    }

    float finalCost;
    if (discount == 0)
    {
        finalCost = fixedPrice / 100 * productAmount;
    }
    else
    {
        float productCost = fixedPrice / 100 * productAmount;
        finalCost = productCost - productCost * discount / 100;
    }

    std::cout << "Purchase price: " << finalCost;

    return 0;
}