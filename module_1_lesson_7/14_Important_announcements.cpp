/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Практическая работа

//Задание 6. Важные объявления

#include <iostream>

int main()
{
	std::cout << "Enter the total length of the header: ";
	int symbolCount;
	std::cin >> symbolCount;

	while (symbolCount <= 0)
	{
		std::cout << "Error! Try again.\n";
		std::cin >> symbolCount;
	}

	int exclamationCount;
	bool correctNumber = false;
	do
	{
		std::cout << "Enter the number of exclamation marks: ";

		std::cin >> exclamationCount;

		if (exclamationCount > symbolCount - 2)
			std::cout << "The number of exclamation marks must be at least two characters less than the length of the header.";
		else
			correctNumber = true;
	} while (!correctNumber);

	int edgeCount = (symbolCount - exclamationCount) / 2;


	for (int currentSymbol = 1; currentSymbol <= symbolCount; ++currentSymbol)
	{
		if (currentSymbol <= edgeCount)
			std::cout << "~";
		else if (currentSymbol <= edgeCount + exclamationCount)
			std::cout << "!";
		else
			std::cout << "~";
	}

	return 0;
}