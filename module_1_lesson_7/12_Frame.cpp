/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Практическая работа

//Задание 4. Рамка

#include <iostream>

int main()
{
	std::cout << "Enter width and height: ";
	int width, height;
	std::cin >> width >> height;

	while (width <= 0 || height <= 0)
	{
		std::cout << "Error! Enter width and height: ";
		std::cin >> width >> height;
	}

	for (int heightStart = 1; heightStart <= height; ++heightStart)
	{
		for (int widthStart = 1; widthStart <= width; ++widthStart)
		{
			if (widthStart == 1 || widthStart == width)
			{
				std::cout << "|";
			}
			else if (heightStart == 1 || heightStart == height)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	return 0;
}