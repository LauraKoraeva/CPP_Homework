/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 7. Почти «Майнкрафт»

#include <iostream>
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

int main()
{
    const int row = 5;
    const int col = 5;
    const int lev = 10;

    std::cout << "Input matrix of heights:\n";
    int height[row][col] = { { 0 } };
    for (int i = 0; i < row; ++i)
    {
        printf("Row: %d\n", i + 1);
        for (int j = 0; j < col; ++j)
        {
            do
            {
                std::cin >> height[i][j];
                if (height[i][j] > 10 || height[i][j] < 0)
                    std::cout << "Height cannot be lower than 0 or higher than 10.\n";
            } while (!correctInput(height[i][j]) || height[i][j] > 10 || height[i][j] < 0);
        }
    }

    std::cout << "Input level:\n";
    int level;
    do
    {
        std::cin >> level;
        if (level > 10 || level < 0)
            std::cout << "Level cannot be equal to 0, lower than 0 or higher than 10.\n";
    } while (!correctInput(level) || level > 10 || level <= 0);
    

    int world[lev][row][col] = { { { 0 } } };

    for (int k = 0; k < lev; ++k)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (height[i][j] >= level)
                    world[k][i][j] = 1;
                else
                    world[k][i][j] = 0;
            }
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << world[level - 1][i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
