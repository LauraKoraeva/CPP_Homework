/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 4. Умножение матрицы на вектор

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(float input)
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

void getArray_2D(float* arr_2D, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < col; ++j)
        {
            do
            {
                std::cin >> *((arr_2D + i * col) + j);
            } while (!correctInput(*((arr_2D + i * col) + j)));
        }
        std::cout << '\n';
    }
}

void getArray(float* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        do
        {
            std::cin >> *(arr + i);
        } while (!correctInput(*(arr + i)));
    }
}

void multiply(float* arr_2D, float* arr, int row, int col, int length, float *arrMultiplied)
{
    for (int j = 0; j < col; ++j)
    {
        for (int i = 0; i < row; ++i)
        {
            *(arrMultiplied + i) += *((arr_2D + i * col) + j) * *(arr + i);
        }
    }
}

void printArray(float* arr, int length)
{
    for (int i = 0; i < length; ++i)
        std::cout << *(arr + i) << " ";
}

int main()
{
    const int row = 4;
    const int col = 4;
    float arr_2D[row][col];
    std::cout << "Enter 2D array:\n";
    getArray_2D((float*)arr_2D, row, col);

    const int length = 4;
    float arr[length];
    std::cout << "Enter array:\n";
    getArray(arr, length);

    float arrMultiplied[length] = { 0 };

    multiply((float*)arr_2D, arr, row, col, length, arrMultiplied);

    std::cout << "~~~~~~~~~~~~~~~\n";
    printArray(arrMultiplied, length);

    return 0;
}