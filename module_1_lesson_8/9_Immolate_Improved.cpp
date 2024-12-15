/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Практическая работа

//Задание 2. Immolate Improved!

#include <iostream>

int main()
{
	float health = 1;

	float resistance;
	do
	{
		std::cout << "Enter orc's resistance power: ";
		std::cin >> resistance;

		if (resistance < 0 || resistance > 1)
			std::cout << "Error!\n";

	} while (resistance < 0 || resistance > 1);

	while (health > 0)
	{
		float impactPower;
		do
		{
			std::cout << "Enter fireball's impact power: ";
			std::cin >> impactPower;

			if (impactPower < 0 || impactPower > 1)
				std::cout << "Error!\n";
		} while (impactPower < 0 || impactPower > 1);

		float damage = impactPower - (impactPower * resistance);
		health -= damage;

		std::cout << "Health damage: " << damage << '\n';
		if (health < 0)
		{
		}
		else
			std::cout << "Life left: " << health << '\n';
	}

	std::cout << "Orc is dead!\n";

	return 0;
}