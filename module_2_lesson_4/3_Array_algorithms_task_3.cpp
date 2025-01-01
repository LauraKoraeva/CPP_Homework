/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

// Задача 3

#include <iostream>
#include <vector>  
#include <algorithm>
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

void showFifthElement(std::vector<int>& vec)
{
    std::sort(vec.begin(), vec.end());

    if (vec.size() >= 5)
        std::cout << "The fifth element: " << vec[4] << '\n';
    else
        std::cout << "There is no fifth element, but the max number is: " << *(vec.end() - 1);
}

void addNumber(std::vector<int>& vec, int number)
{
    vec.push_back(number);
}

int main()
{
    std::vector<int> numbers;
    int number;

    std::cout << "Enter as many numbers as is required.\n";
    std::cout << "To see the fifth element enter -1\n";
    std::cout << "To exit enter -2\n";

    while (true)
    {
        do
        {
            std::cin >> number;
        } while (!correctInput(number));
         
        if (number == -1)
        {
            showFifthElement(numbers);
        }
        else if (number == -2)
        {
            return 0;
        }
        else
            addNumber(numbers, number);
    }
}

