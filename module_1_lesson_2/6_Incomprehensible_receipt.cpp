/*Основы программирования на C++
Урок 2. Целочисленные переменные. Данные и вычисления
*/

//Практическая работа

//Задание 4. Непонятная квитанция

#include <iostream>

int main()
{
  std::cout << "Welcome to the property management calculator!\n";
  std::cout << "Enter the amount indicated on the receipt: ";
  int totalSum;
  std::cin >> totalSum;

  std::cout << "How many entrances are there in your block of flats? ";
  int blocksCount;
  std::cin >> blocksCount;
  
  std::cout << "How many apartments are there in each entrance? ";
  int flatsPerBlock;
  std::cin >> flatsPerBlock;

  int flatsCount = blocksCount * flatsPerBlock;
  int sumPerFlat = totalSum / flatsCount;

  std::cout << "Each apartment has to pay " << sumPerFlat << " RUB.\n";
  
  return 0;
}