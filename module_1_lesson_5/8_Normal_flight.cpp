/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Практическая работа

//Задание 1. Полёт нормальный!

#include <iostream>

int main()
{
  int speed;
  int altitude;
  
  std::cout << "Enter the speed of the aircraft: ";
  std::cin >> speed;
  std::cout << "Enter the aircraft's flight altitude: ";
  std::cin >> altitude;

  if (speed >= 750 && speed <= 850 && altitude >= 9000 && altitude <= 9500)
    std::cout << "The plane is flying at the correct flight level.";
  else
    std::cout << "The plane is flying at the wrong flight level";
    
  return 0;
}