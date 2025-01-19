// Продвинутые темы и техники C++
// Урок 5. Макросы и препроцессор

//Задание 1. Реализация продвинутого ввода и вывода дней недели

#include <iostream>
#include <limits> 
#include <numeric>

#define WEEKDAY(n)  (((n) == 1) ? "Monday" : ((n) == 2) ? "Tuesday" : ((n) == 3) ? "Wednesday" : \
((n) == 4)  ?  "Thursday" : ((n) == 5) ?  "Friday" : ((n) == 6) ?  "Saturday" : ((n) == 7) ?  "Sunday" : "Error")

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

int main()
{
    std::cout << "Enter the day of the week:\n";
    int day;
    do
    {
        std::cin >> day;
    } while (!correctInput(day));
    std::cout << WEEKDAY(day);
}
