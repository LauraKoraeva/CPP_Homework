/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Задача 1. Калькулятор скидки

#include <iostream>

int main()
{
  double itemCost1;
  double itemCost2;
  double itemCost3;
  double discount = 0.0;
  double discountAmount = 0.0;
  std::cout << "Let's calculate the check amount.\n";
  std::cout << "Enter the cost of the first item: ";
  std::cin >> itemCost1;
  std::cout << "Enter the cost of the second item: ";
  std::cin >> itemCost2;
  std::cout << "Enter the cost of the third item: ";
  std::cin >> itemCost3;

  double totalCost = itemCost1 + itemCost2 + itemCost3;

  if (totalCost > 10000)
  {
    discount = 10.0;
    std::cout << "\nSince your check amount exceeds 10,000 rubles, you are given a 10% discount..\n";
    discountAmount = discount / 100 * totalCost;
    std::cout << "Discount: " << discountAmount << '\n';
  }

  double finalPrice = totalCost - discountAmount;
  std::cout << "\nTotal amount to be paid: " << finalPrice << '\n';

  return 0;
}