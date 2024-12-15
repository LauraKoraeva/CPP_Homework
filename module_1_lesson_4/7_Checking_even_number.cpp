/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Практическая работа

//Задание 3. Проверка на чётное число

#include <iostream>

int main()
{
  std::cout << "Find out if a number is even or odd?\n";
  std::cout << "Enter a number: ";
  int number;
  std::cin >> number;
  int remainder = number % 2;
  std::cout << "-----Checking-----\n";
  if (remainder == 0)
  {
    std::cout << "Number " << number << " is even";
  }
  else
  {
    std::cout << "Number " << number << " is odd";
  }

  return 0;
}
