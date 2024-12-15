/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 2. Крестики-нолики

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n' || input < 0 || input >= 3)
	{
		std::cout << "Coordinates are wrong. Try again!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

void makeMove(std::string name, char symbol, char(*grid)[3], bool(*moves)[3])
{
	int i, j;
	do
	{
		std::cout << name << ", enter coordinates : \n";

		do
		{
			std::cout << "y - ";
			std::cin >> i;
		} while (!correctInput(i));

		do
		{
			std::cout << "x - ";
			std::cin >> j;
		} while (!correctInput(j));

		if (moves[i][j])
			std::cout << "Coordinates are taken. Try again!\n";
	} while (moves[i][j] == true);

	moves[i][j] = true;
	grid[i][j] = symbol;
}

bool checkDiagonal(const char(*grid)[3], char symbol)
{
	bool hasWinner = false;
	int count_1 = 0;
	int count_2 = 0;

	int i_1 = 0;
	int j_1 = 0;
	while (i_1 != 3)
	{
		if (grid[i_1][j_1] == symbol)
			++count_1;

		if (count_1 == 3)
		{
			hasWinner = true;
			return hasWinner;
		}
		++i_1;
		++j_1;
	}

	int i_2 = 0;
	int j_2 = 2;
	while (i_2 != 3)
	{
		if (grid[i_2][j_2] == symbol)
			++count_2;

		if (count_2 == 3)
		{
			hasWinner = true;
			return hasWinner;
		}
		++i_2;
		--j_2;
	}

	return hasWinner;
}

bool hasWinner(const char(*grid)[3], char symbol)
{
	bool hasWinner = false;
	int count_H = 0;
	int count_V = 0;

	if (checkDiagonal(grid, symbol))
	{
		hasWinner = true;
		return hasWinner;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[i][j] == symbol)
				++count_H;

			if (i == 0)
			{
				for (int k = 0; k < 3; ++k)
				{
					if (grid[k][j] == symbol)
						++count_V;
				}

				if (count_V == 3)
				{
					hasWinner = true;
					return hasWinner;
				}
				else
					count_V = 0;
			}
		}
		if (count_H == 3)
		{
			hasWinner = true;
			return hasWinner;
		}
		else
			count_H = 0;
	}

	return hasWinner;
}

void printGrid(const char(*grid)[3])
{
	std::cout << "_________________________________\n";
	std::cout << " ----------- \n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "| ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout << grid[i][j] << " | ";
		}
		std::cout << "\n";
		if (i < 2)
			std::cout << "|---|---|---|\n";
	}
	std::cout << " ----------- \n";
	std::cout << "_________________________________\n";
}

int main()
{
	char grid[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
	bool moves[3][3] = { false };

	std::cout << "Player 1, enter your name: ";
	std::string playerOne;
	std::cin >> playerOne;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Player 2, enter your name: ";
	std::string playerTwo;
	std::cin >> playerTwo;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	char symbolX = 'X';
	char symbolO = 'O';

	bool isDraw = true;

	printGrid(grid);

	int movesCount = 9;
	int count = 0;
	while (count < movesCount)
	{
		if (count % 2 == 0)
		{
			makeMove(playerOne, symbolX, grid, moves);
			printGrid(grid);
			if (hasWinner(grid, symbolX))
			{
				std::cout << playerOne << ", you have won! Congratulations!\n";
				isDraw = false;
				break;
			}
		}
		else
		{
			makeMove(playerTwo, symbolO, grid, moves);
			printGrid(grid);
			if (hasWinner(grid, symbolO))
			{
				std::cout << playerTwo << ", you have won! Congratulations!\n";
				isDraw = false;
				break;
			}
		}
		++count;
	}
	if (isDraw)
		std::cout << "It's a draw!\n";

	return 0;
}

