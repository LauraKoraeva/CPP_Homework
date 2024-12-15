/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Циклы for

//Задача 5. Начальник (цикл for).

#include <iostream>
#include <string>

int main()
{
    std::string answer;
    int count = 0;

    for (; answer != "Yes, of course I have"; )
    {
        std::cout << "Have you completed the task?";
        std::getline(std::cin, answer);
        ++count;
    }

    std::cout << "Why do I have to ask " << count << " times?";

    return 0;
}
