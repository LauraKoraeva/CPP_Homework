/*Массивы и Указатели в C++
Урок 1. Одномерные массивы. Базовые алгоритмы на массивах*/

//Задание 1. Многоквартирный дом

#include <iostream>
#include <string>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

int main()
{
	std::cout << "Enter owners' surnames:\n";
	std::string owner[10];
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> owner[i];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	for (int count = 0; count < 3; ++count)
	{
		std::cout << "Enter apartment number: ";
		int apartment;
		std::cin >> apartment;

		while (!correctInput(apartment) || apartment < 1 || apartment > 10)
		{
			std::cout << "The number must be an integer between 1 and 10. Try again: ";
			std::cin >> apartment;
		}

		std::cout << owner[apartment - 1] << " lives in Apartment #" << apartment << '\n';
	}

	return 0;
}