/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Пользовательский ввод

//Задание 2

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

    while (discount > itemPrice)
    {
        std::cout << "Error! Enter discount.\n";
        std::cin >> discount;
    }

    int totalPrice = itemPrice + deliveryPrice - discount;
    std::cout << "\nTotal price: $" << totalPrice << '\n';

    return 0;
}