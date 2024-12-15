/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Логические операторы и сложные условия

//Задача 3. Треугольник.

#include <iostream>


int main()
{
  std::cout << "Enter the lengths of the three sides of the triangle: ";
  int a, b, c;
  std::cin >> a >> b >> c;

  if (a + b <= c || a + c <= b || b + c <= a)
    std::cout << "Triangle is not possible.";
  else
    std::cout << "Triangle is possible.";
  
  return 0;
}