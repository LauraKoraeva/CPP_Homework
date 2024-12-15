/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Тип данных float

//Задача 2. ЗОЖ

#include <iostream>

int main()
{
    std::cout << "Enter the amount of protein per 100 grams of product: ";
    float protein;
    std::cin >> protein;

    while (protein < 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> protein;
    }

    std::cout << "Enter the amount of carbohydrates per 100 grams of product: ";
    float carbs;
    std::cin >> carbs;

    while (carbs < 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> carbs;
    }

    std::cout << "Enter the net weight of the product: ";
    float netWeight;
    std::cin >> netWeight;

    while (netWeight <= 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> netWeight;
    }

    float proteinPerServing = netWeight / 100 * protein;
    float carbsPerServing = netWeight / 100 * carbs;

    std::cout << '\n';

    std::cout << "With a net weight of " << netWeight << " g of the product, it is consumed:\n";
    std::cout << "Protein\t\t" << proteinPerServing << " g\n";
    std::cout << "Carbohydrates\t" << carbsPerServing << " g\n";

    return 0;
}