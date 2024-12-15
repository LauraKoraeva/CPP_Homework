/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Практическая работа

//Задание 1. Космический симулятор

#include <iostream>
#include <cmath>

int main()
{
	float mass;
	do
	{
		std::cout << "Input mass: ";
		std::cin >> mass;
		if (mass <= 0)
			std::cout << "Mass cannot be equal to zero or less than zero.\n";
	} while (mass <= 0);

	std::cout << "Input force: ";
	float force;
	std::cin >> force;

	while (force <= 0)
	{
		std::cout << "Error! Input force:\n";
		std::cin >> force;
	}

	std::cout << "Input time: ";
	float time;
	std::cin >> time;

	while (time <= 0)
	{
		std::cout << "Error! Input time:\n";
		std::cin >> time;
	}

	float acceleration = force / mass;

	float distance = (acceleration * std::pow(time, 2.0)) / 2;

	std::cout << "In " << time << " seconds, the spacecraft will cover a distance of " << distance << " km.";

	return 0;
}
