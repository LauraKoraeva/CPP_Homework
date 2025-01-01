/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 5. Пупырка

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input < 0 || input > 11)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

void initialize(bool* wrap, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            *((wrap + i * col) + j) = true;
        }
    }
}

void initialize(char* wrap, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            *((wrap + i * col) + j) = 'o';
        }
    }
}

void printWrap(char* wrap, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << *((wrap + i * col) + j) << " ";
        }
        std::cout << '\n';
    }
}

int getCoordinate()
{
    int coordinate;
    do
    {
        std::cin >> coordinate;
    } while (!correctInput(coordinate));

    return coordinate;
}

void pop(bool* wrapBool, int row, int col, char* wrapChar, int& count)
{
    int start_i, start_j, end_i, end_j;
    std::cout << "Enter the first coordinates:\n";
    std::cout << "row: ";
    start_i = getCoordinate();
    std::cout << "col: ";
    start_j = getCoordinate();
    std::cout << "Enter the last coordinates:\n";
    std::cout << "row: ";
    end_i = getCoordinate();
    std::cout << "col: ";
    end_j = getCoordinate();

    if (start_i > end_i)
        std::swap(start_i, end_i);
    if (start_j > end_j)
        std::swap(start_j, end_j);

    for (int i = start_i; i <= end_i; ++i)
    {
        for (int j = start_j; j <= end_j; ++j)
        {
            if (*((wrapBool + i * col) + j) == true)
            {
                std::cout << "Pop!\n";
                *((wrapBool + i * col) + j) = false;
                *((wrapChar + i * col) + j) = 'x';
                --count;
            }
        }
    }
    printWrap((char*)wrapChar, row, col);
}

int main()
{
    const int row = 12;
    const int col = 12;
    bool wrapBool[row][col];
    char wrapChar[row][col];
    initialize((bool*)wrapBool, row, col);
    initialize((char*)wrapChar, row, col);

    printWrap((char*)wrapChar, row, col);

    int count = row * col;
    while (count > 0)
    {
        pop((bool*)wrapBool, row, col, (char*)wrapChar, count);
    }

    return 0;
}




