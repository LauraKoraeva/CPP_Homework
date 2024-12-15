/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Практическая работа

#include <iostream>

int main()
{
  int initialHeight = 100;
  int dailyGrowth = 50;
  int nightlyLoss = 20;

  std::cout << "The height of the bamboo by the middle of what day are you interested in? ";
  int dayNumber;
  std::cin >> dayNumber;

  int currentHeight = initialHeight + (dailyGrowth - nightlyLoss) * (dayNumber - 1) + dailyGrowth / 2;

  std::cout << "The height of the bamboo by the middle of day " << dayNumber << " will be " << currentHeight << " cm.\n";

  return 0; 
}