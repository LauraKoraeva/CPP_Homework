/*Основы программирования на C++
Урок 2. Целочисленные переменные. Данные и вычисления
*/

//Практическая работа

//Задание 3. Время, время!

#include <iostream>

int main()
{
  std::cout << "This program calculates how many customers the cashier will have time to serve per shift.\n";
  
  std::cout << "Enter the shift duration in minutes: ";
  int shiftDuration;
  std::cin >> shiftDuration;

  std::cout << "How many minutes does the customer make an order? ";
  int orderDuration;
  std::cin >> orderDuration;
  
  std::cout << "How many minutes does it take the cashier to collect the order? ";
  int executionDuration;
  std::cin >> executionDuration;

  int serviceDuration = orderDuration + executionDuration;
  int customersCount = shiftDuration / serviceDuration;
  
  std::cout << "During a " << shiftDuration << "-minute shift the chashier will have time to serve " << customersCount << " clients.\n";

return 0;
}