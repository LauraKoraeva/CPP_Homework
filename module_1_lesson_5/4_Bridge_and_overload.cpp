/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Логические операторы и сложные условия

//Задача 2. Мост и перегрузка.

#include <iostream>


int main()
{
  int car1, car2, car3, car4;
  std::cout << "Enter the mass of the first car: ";
  std::cin >> car1;
  std::cout << "Enter the mass of the second car: ";
  std::cin >> car2;
  std::cout << "Enter the mass of the third car: ";
  std::cin >> car3;
  std::cout << "Enter the mass of the fourth car: ";
  std::cin >> car4;

  int maxWeight = 1200;

  if (car1 > maxWeight || car2 > maxWeight || car3 > maxWeight || car4 > maxWeight)
    std::cout << "The mass of one of the cars exceeds 1200 kg.\n";
  else
    std::cout << "The mass of all the cars is less than 1200 kg.\n";
  
  return 0;
}