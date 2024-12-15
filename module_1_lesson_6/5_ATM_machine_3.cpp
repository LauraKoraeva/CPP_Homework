/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while

//Задача 5. Банкомат 3.0.

#include <iostream>

int main()
{
    std::cout << "Enter four numbers: \n";
    int number1, number2, number3, number4;
    std::cin >> number1 >> number2 >> number3 >> number4;

    while (number1 + number2 + number3 + number4 != 42)
    {
        std::cout << "The input is incorrect, please try again.\n";
        std::cin >> number1 >> number2 >> number3 >> number4;
    }

    std::cout << "The input is correct.\n";
    return 0;
}