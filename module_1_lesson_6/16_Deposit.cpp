/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Практическая работа

//Задание 6. Вклады

#include <iostream>

int main()
{
    std::cout << "Enter the deposit amount: ";
    int deposit;
    std::cin >> deposit;

    while (deposit <= 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> deposit;
    }

    std::cout << "Enter the interest rate: ";
    int rate;
    std::cin >> rate;

    std::cout << "Enter the desired amount: ";
    int desiredAmount;
    std::cin >> desiredAmount;

    while (desiredAmount <= 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> desiredAmount;
    }

    int yearsCount = 0;

    while (deposit < desiredAmount)
    {
        deposit = deposit + ((rate * deposit) / 100);
        ++yearsCount;
    }

    std::cout << "You'll have to wait " << yearsCount << " years\n";

    return 0;
}