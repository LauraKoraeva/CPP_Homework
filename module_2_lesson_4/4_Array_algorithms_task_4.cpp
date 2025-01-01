/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

// Задача 4

#include <iostream>
#include <vector>

void sortNumbers(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size() - i - 1; ++j)
        {
            int abs_1 = abs(vec[j]);
            int abs_2 = abs(vec[j + 1]);

            if (abs_1 > abs_2)
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void printNumbers(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
}

int main()
{
    std::vector<int> numbers = { -100,-50, -5, 1, 10, 15 };

    sortNumbers(numbers);

    printNumbers(numbers);

    return 0;
}


