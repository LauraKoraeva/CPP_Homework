/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Практическая работа

//Задание 4. Убийца Steam

#include <iostream>

int main()
{
	float fileSize;
	do
	{
		std::cout << "Enter file size: ";
		std::cin >> fileSize;

		if (fileSize <= 0)
			std::cout << "Error!\n";
	} while (fileSize <= 0);
	
	float downloadSpeed;
	do
	{
		std::cout << "Enter downloading speed: ";
		std::cin >> downloadSpeed;

		if (downloadSpeed <= 0)
			std::cout << "Error!\n";
	} while (downloadSpeed <= 0);

	int secondsCount = 0;
	float downloaded = 0;
	float fileLeft = fileSize;
	int percent = 0;

	while (fileLeft > 0)
	{
		if (fileLeft < downloadSpeed)
		{
			downloaded += fileLeft;
			fileLeft -= fileLeft;
			++secondsCount;
			percent = (100 / fileSize) * downloaded;
		}
		else
		{
			downloaded += downloadSpeed;
			fileLeft -= downloadSpeed;
			++secondsCount;
			percent = (100 / fileSize) * downloaded;
		}

		std::cout << "Time passed: " << secondsCount << " sec. Downloaded: " << downloaded << " MB out of " << fileSize << " (" << percent << "%).\n";
	}

	return 0;
}