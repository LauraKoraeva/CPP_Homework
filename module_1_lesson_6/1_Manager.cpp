/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while

//Задача 1. Начальник.

#include <iostream>
#include <string>

int main()
{
    std::string answer;

    do {
        std::cout << "Have you completed the task?\n";
        std::getline(std::cin, answer);
    } while (answer != "Yes, of course I have");

    return 0;
}
