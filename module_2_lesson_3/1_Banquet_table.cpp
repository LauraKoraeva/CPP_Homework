/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 1. Банкетный стол

#include <iostream>

void printArray(int *arr, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << *((arr + i * col) + j) << " ";
        }
        std::cout << '\n';
    }
}

void printAll(int* cutlery, int* plates, int* chairs, int row, int col)
{
    std::cout << "Cutlery\n";
    printArray((int*)cutlery, row, col);
    std::cout << "Plates\n";
    printArray((int*)plates, row, col);
    std::cout << "Chairs\n";
    printArray((int*)chairs, row, col);
    std::cout << '\n';
}

int main()
{
    const int row = 2;
    const int col = 6;
    
    int cutlery[row][col] = {
        { 4, 3, 3, 3, 3, 3 },
        { 4, 3, 3, 3, 3, 3 }
    };

    int plates[row][col] = {
        { 3, 2, 2, 2, 2, 2 },
        { 3, 2, 2, 2, 2, 2 }
    };

    int chairs[row][col] = {
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 }
    };

    std::cout << "~~~Before the Dinner~~~\n";
    printAll((int*)cutlery, (int*)plates, (int*)chairs, row, col);

    chairs[0][4] += 1;
    cutlery[1][2] -= 1;
    cutlery[1][0] -= 1;
    cutlery[1][2] += 1;
    plates[1][0] -= 1;

    std::cout << "~~~After the Dinner~~~\n";
    printAll((int*)cutlery, (int*)plates, (int*)chairs, row, col);

    return 0;
}
