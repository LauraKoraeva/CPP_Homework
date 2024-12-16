/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 6. Проход змейкой

#include <iostream>

int main()
{
    const int row = 5;
    const int col = 5;
    int digits[row][col];

    int number = 0;
    int multiplier = -1;
    int mid = col / 2; 

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            digits[i][mid + ((col - 1 - mid) * multiplier) - (j * multiplier)] = number;
            ++number;
        }
        multiplier *= -1;
    }
    
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%2d ", digits[i][j]);
        }
        std::cout << "\n";
    }
    return 0;
}