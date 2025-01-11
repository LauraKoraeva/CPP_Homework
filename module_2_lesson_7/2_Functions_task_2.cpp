/*Массивы и Указатели в C++
Урок 7. Расширенная работа с функциями*/

//Задача 2

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input <= 0)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

void countWays(int place, int& count, int stairs, int pace = 3)
{
    if (place > stairs)
        return;
    else if (place == stairs)
        ++count;
    else
    {
        for (int i = 1; i <= pace; i++)
            countWays(place + i, count, stairs, pace = 3);
    }
}

int main()
{
    std::cout << "How many stairs does the rabbit have to climb? ";
    int stairs;
    do
    {
        std::cin >> stairs;
    } while (!correctInput(stairs));

    int place = 0;
    int count = 0;
    countWays(place, count, stairs);

    std::cout << "The rabbit has " << count << " ways to climb " << stairs << " stairs.";

    return 0;
}

