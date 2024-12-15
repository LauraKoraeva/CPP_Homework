/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Практическая работа

//Задание 4. Банкомат — 2

#include <iostream>

int main()
{
  int banknote_5000;
  int banknote_2000;
  int banknote_1000;
  int banknote_500;
  int banknote_200;
  int banknote_100;
  int sum;
  std::cout << "Enter sum: ";
  std::cin >> sum;

  if ((sum % 100 != 0) || (sum > 150000))
  {
    std::cout << "Error!";
  }
  else
  {
    if (sum >= 5000)
    {
      banknote_5000 = sum / 5000;
      std::cout << banknote_5000 << " - 5000, ";
      sum -= (5000 * banknote_5000);
    }
    if (sum >= 2000)
    {
      banknote_2000 = sum / 2000;
      std::cout << banknote_2000 << " - 2000, ";
      sum -= (2000 * banknote_2000);
    }
    if (sum >= 1000)
    {
      banknote_1000 = sum / 1000;
      std::cout << banknote_1000 << " - 1000, ";
      sum -= (1000 * banknote_1000);
    }
    if (sum >= 500)
    {
      banknote_500 = sum / 500;
      std::cout << banknote_500 << " - 500, ";
      sum -= (500 * banknote_500);
    }
    if (sum >= 200)
    {
      banknote_200 = sum / 200;
      std::cout << banknote_200 << " - 200, ";
      sum -= (200 * banknote_200);
    }
    if (sum >= 100)
    {
      banknote_100 = sum / 100;
      std::cout << banknote_100 << " - 100, ";
      sum -= (200 * banknote_100);
    }
  }
    return 0;
}