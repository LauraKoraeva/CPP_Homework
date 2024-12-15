/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Пользовательский ввод

//Задание 1

#include <iostream>

int main()
{
  std::cout << "Enter an integer to calculate its square: ";
  int a;
  std::cin >> a;

  int square = a * a;

  std::cout << "The square of " << a << " is " << square << '\n';

  return 0;
}