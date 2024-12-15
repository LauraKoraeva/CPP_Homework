/*Основы программирования на C++
Урок 10. Установка и настройка IDE*/

#include <iostream>
#include <cmath>

int main()
{
	float a, b, c;
	std::cout << "Input a, b, c:\n";
	std::cin >> a >> b >> c;

	if (a == 0)
	{
		std::cout << "Not a quadratic equation!" << std::endl;
	}
	else 
	{
		float discriminant = b * b - 4 * a * c;

		if (discriminant > 0)
		{
			float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
			float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
			std::cout << "Root 1: " << x1 << "\nRoot 2: " << x2 << std::endl;
		}
		else if (discriminant == 0)
		{
			float x = std::fabs(b) / (2 * a);
			std::cout << "Root: " << x << std::endl;
		}
		else
		{
			std::cout << "No valid roots!" << std::endl;
		}
	}

	return 0;
}