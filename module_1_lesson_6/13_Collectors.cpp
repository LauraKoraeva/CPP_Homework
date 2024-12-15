/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Практическая работа

//Задание 3. Коллекторы

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter the name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter the amount of debt: ";
    int debt;
    std::cin >> debt;
    
    if (debt < 0)  
        std::cout << "The amount of debt cannot be negative! \n";
    else 
    {
        while (debt > 0)
        {
            std::cout << "Enter the payment amount: ";
            int payment;
            std::cin >> payment;
            debt -= payment;
            if (debt > 0)
                std::cout << "The amount of debt: " << debt << '\n';
        }

        std::cout << "The debt has been fully repaid.\n";
        if (debt != 0)
        {
            int balance = -debt;
            std::cout << "Account balance: " << balance << '\n';
        }
    }
    return 0;
}