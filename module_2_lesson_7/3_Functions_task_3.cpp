/*Массивы и Указатели в C++
Урок 7. Расширенная работа с функциями*/

//Задача 3

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input == 0)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

void evenDigits(long long number, int& ans)
{
    if (number == 0)
        return;

    int digit = number % 10;

    if (digit % 2 == 0)
        ++ans;

    number /= 10;

    evenDigits(number, ans);
}

int main()
{
    std::cout << "Enter a number: ";
    long long number;
    do
    {
        std::cin >> number;
    } while (!correctInput(number));

    int ans = 0;

    evenDigits(number, ans);

    std::cout << "Even digits: " << ans;

    return 0;
}

