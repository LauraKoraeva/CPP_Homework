/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while

//Задача 2. Купи слона.

#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? \n";
    std::string name;
    std::getline(std::cin, name);
    std::cout << name << ", buy an elephant!\n";
    std::string answer;
    std::getline(std::cin, answer);
    
  while (1 > 0)
    {
    std::cout << "Everyone says \"" << answer << "\", and you buy an elephant!\n";
      std::getline(std::cin, answer);
    }

    return 0;
}