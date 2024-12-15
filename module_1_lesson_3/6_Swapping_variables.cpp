/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Практическая работа

//Задание 2. Обмен местами

#include <iostream>

int main()
{
  int a = 5;
  int b = 7;
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';
  int temp = a;
  a = b;
  b = temp;
  std::cout << "Swapping variables" << '\n';
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';

  return 0; 
}