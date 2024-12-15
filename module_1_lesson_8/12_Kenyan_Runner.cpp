/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Практическая работа

//Задание 5. Кенийский бегун

#include <iostream>

int main()
{
	int kilometresCount;
	do
	{
		std::cout << "How many kilometres did you run today? ";
		std::cin >> kilometresCount;

		if (kilometresCount <= 0)
			std::cout << "Error!\n";
	} while (kilometresCount <= 0);

	float total = 0;

	int index = 1;
	while (index <= kilometresCount)
	{
		float pace;
		do
		{
			std::cout << "Enter your pace at kilometre " << index << ": ";
			std::cin >> pace;

			if (pace <= 0)
				std::cout << "Error!\n";
		} while (pace <= 0);

		total += pace;
		index++;
	}
	
	int minutes = total / kilometresCount / 60;
	int seconds = (int) std::round(total / kilometresCount) % 60;

	std::cout << "Your average pace: " << minutes << " minutes " << seconds << " sec.\n";

	return 0;
}

