/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Вложенные конструкции if

//Задача 2. Банкомат.

#include <iostream>


int main()
{
  std::cout << "Enter the amount to withdraw: ";
  int sum;
  std::cin >> sum;
  if (sum < 100000)
  {
    if (sum % 100 == 0)
      std::cout << "The amount is available for withdrawal.";
    else
      std::cout << "The amount is not available for withdrawal.";
  }
  else
    std::cout << "The amount is not available for withdrawal.";
  
  return 0;
}