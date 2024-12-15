/*Основы программирования на C++
Урок 2. Целочисленные переменные. Данные и вычисления
*/

//Практическая работа

//Задание 2. Калькулятор стоимости товара

#include <iostream>

int main()
{
    std::cout << "Enter price: ";
    int itemPrice;
    std::cin >> itemPrice;
  
    std::cout << "Enter delivery price: ";
    int deliveryPrice;
    std::cin >> deliveryPrice;
  
    std::cout << "Enter discount: ";
    int discount;
    std::cin >> discount;
  
    int totalPrice = itemPrice + deliveryPrice - discount;
    std::cout << "\nTotal price: $" << totalPrice << '\n';

    return 0;

}