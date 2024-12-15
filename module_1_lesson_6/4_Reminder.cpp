/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while

//Задача 4. Напоминалка.

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter reminder text: ";
    std::string reminderText;
    std::getline(std::cin, reminderText);

    std::cout << "Enter the number of reminders: ";
    int reminderCount;
    std::cin >> reminderCount;

    int count = 1;
    while (count <= reminderCount)
    {
        std::cout << count << ". " << reminderText << '\n';
        ++count;
    }

    return 0;
}