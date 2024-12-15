/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Упрощение логических выражений. Приоритеты операторов

//Задача 1. Военкомат.

#include <iostream>
#include <string>

int main()
{
  int height;
  int weight;
  int hands;
  int legs;
  int flightHours;
  std::string eyeColour;

  std::cout << "Enter height: ";
  std::cin >> height;
  std::cout << "Enter weight: ";
  std::cin >> weight;
  std::cout << "Enter the number of hands: ";
  std::cin >> hands;
  std::cout << "Enter the number of legs: ";
  std::cin >> legs;
  std::cout << "Enter the number of flight hours: ";
  std::cin >> flightHours;
  std::cout << "Enter the eye color: ";
  std::cin >> eyeColour;

  if ((height >= 145 && height < 165) && (weight >= 45 && weight < 65) && (legs == hands) && (flightHours > 100) && (eyeColour != "green"))
    std::cout << "Fit for the army!" << '\n';
  else
    std::cout << "Not fit for the army!" << '\n';

  return 0;
}
