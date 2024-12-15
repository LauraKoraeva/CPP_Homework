/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Упрощение логических выражений. Приоритеты операторов

//Задача 2. — Входит... И выходит... И входит... Замечательно выходит! "Винни-Пух и день забот".
#include <iostream>

int main()
{
  int length;
  int width;
  int height;
  std::cout << "Enter the brick dimensions: \n";
  std::cin >> length >> width >> height;

  int x;
  int y;
  std::cout << "Enter the hole dimensions: \n";
  std::cin >> x >> y;

  if ((length <= x && width <= y || length <= y && width <= x) || (length <= x && height <= y || length <= y && height <= x) || (width <= x && height <= y || width <= y && height <= x))
    std::cout << "Hooray!You can give the brick to Eeyore!";
  else
    std::cout << "Nope, you can't give this brick to Eeyore!";
    

  return 0;
}
