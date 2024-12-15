/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Практическая работа

//Задание 5. Кратность числа

#include <iostream>
#include <cassert>

int main()
{
  std::cout << "Find out if one number is divisible by another without a remainder.\n";
  std::cout << "Enter the first number: ";
  int dividend;
  std::cin >> dividend;
  std::cout << "Enter the second number: ";
  int divisor;
  std::cin >> divisor;
  assert(divisor != 0);
  std::cout << "-----Checking-----\n";
  int remainder = dividend % divisor;
  if (remainder == 0)
  {
    std::cout << "Yes, " << dividend << " is divisible by " << divisor << " without a remainder!\n";
  }
  else
  {
    std::cout << "No, " << dividend << " is not divisible by " << divisor << " without a remainder!\n";
  }

  return 0;
}