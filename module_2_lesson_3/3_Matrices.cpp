/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 3. Матрицы

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

void getMatrix(int* matrix, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < col; ++j)
        {
            do
            {
                std::cin >> *((matrix + i * col) + j);
            } while (!correctInput(*((matrix + i * col) + j)));
        }
        std::cout << '\n';
    }
}

bool isDifferent(int* matrix_A, int* matrix_B, int row, int col)
{
    bool isDifferent = false;
    for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
            if (*((matrix_A + i * col) + j) != *((matrix_B + i * col) + j))
				return true;
		}
	}
    return isDifferent;
}

void makeDiagonal(int *matrix, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (i != j)
				*((matrix + i * col) + j) = 0;
		}
	}
}

void printMatrix(int* matrix, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << *((matrix + i * col) + j) << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
	const int row = 4;
	const int col = 4;
	
    int matrix_A[row][col];
	int matrix_B[row][col];
    
    std::cout << "Enter matrix A:\n";
    getMatrix((int*)matrix_A, row, col);
    std::cout << "Enter matrix B:\n";
    getMatrix((int*)matrix_B, row, col);

    if (isDifferent((int*)matrix_A, (int*)matrix_B, row, col))
		std::cout << "Matrix A and Matrix B are different.\n";
	else
	{
		std::cout << "Matrix A and Matrix B are equal.\n";
		makeDiagonal((int*)matrix_A, row, col); 
        printMatrix((int*)matrix_A, row, col);
	}

	return 0;
}