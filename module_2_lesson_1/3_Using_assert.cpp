/*Массивы и Указатели в C++
Урок 1. Одномерные массивы. Базовые алгоритмы на массивах*/

//Задание 3. Использование assert

#include <iostream>
#include <cassert>
#include <limits>
#include <numeric>

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

float travelTime(float distance, float speed)
{
    assert(speed > 0);

    float time = distance / speed;
    return time;
}

int main()
{
    float distance;
    float speed;

    do
    {
        std::cout << "Enter distance: ";
        std::cin >> distance;
    } while (!correctInput(distance));

    do
    {
        std::cout << "Enter speed: ";
        std::cin >> speed;
    } while (!correctInput(speed));

    float time = travelTime(distance, speed);
    std::cout << "Travel time: " << time << '\n';

    return 0;
}