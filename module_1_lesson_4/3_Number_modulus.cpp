/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Задача 3. Модуль числа.

#include <iostream>

int main()
{
  int x;
  std::cout << "Enter a number: ";
  std::cin >> x;

  if (x < 0)
  {
    x = -x;
  }
  std::cout << "The modulus of the number is: " << x << '\n';

  return 0;
}