/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Задача 4. Барберы

#include <iostream>

int main()
{
  std::cout << "Let's find out if you have enough barbers in your city.\n";
  std::cout << "How many men live in the city? ";
  int men;
  std::cin >> men;
  std::cout << "How many barbers are already working in the city? ";
  int barbers;
  std::cin >> barbers;
  
  int term = 30;
  int cutsPerBarber = 8;
  
  int barbersRequired;
  if (men % (term * cutsPerBarber) == 0)
  {
    barbersRequired = men / (term * cutsPerBarber);
  }
  else
  {
    barbersRequired = men / (term * cutsPerBarber) + 1;
  }

  std::cout << "Number of barbers required: " << barbersRequired << '\n';
  
  if (barbers < barbersRequired)
  {
    std::cout << "There are not enough barbers!" << '\n';
    std::cout << "You need to hire " << barbersRequired - barbers << " barbers.\n";
  }
  else
  {
    std::cout << "There are enough barbers!" << '\n';
  }

  return 0;
}