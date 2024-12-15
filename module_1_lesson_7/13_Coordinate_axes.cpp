/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Практическая работа

//Задание 5. Координатные оси

#include <iostream>

int main() 
{
	for (int row = 0; row <= 20; ++row)
	{
		for (int col = 0; col <= 50; ++col)
		{
			if (row == 20 / 2 && col == 50 / 2)
				std::cout << "+";
			else if (row == 0 && col == 50 / 2)
				std::cout << "^";
			else if (row == 20 / 2 && col == 50)
				std::cout << ">";
			else if (row == 20 / 2 && col != 50 / 2 && col != 50)
				std::cout << "-";
			else if (col == 50 / 2 && row != 0)
				std::cout << "|";
			else
				std::cout << " ";
		}
		std::cout << '\n';
	}
	return 0;
}