/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Вложенные конструкции if

//Задача 1. Координатная плоскость.

#include <iostream>


int main()
{
  int x, y;
  std::cout << "Enter the X and Y coordinates: ";
  std::cin >> x >> y;

  if (x > 0)
  {
    if (y > 0)
      std::cout << "The point is in the first quadrant";
    else if (y < 0)
      std::cout << "The point is in the fourth quadrant";
    if (y == 0)
      std::cout << "The point is on the X axis";
  }
  else if (x < 0)
  {
    if (y > 0)
      std::cout << "The point is in the second quadrant";
    else if (y < 0)
      std::cout << "The point is in the third quadrant";
    else if (y == 0)
      std::cout << "The point is on the X axis";
  }
  else if (x == 0)
    std::cout << "The point is on the Y axis";
  
  return 0;
}
