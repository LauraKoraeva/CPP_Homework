/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Строковый тип данных

//Задание 1

#include <iostream>
#include <string>

int main()
{
	std::string playerName;
	std::cout << "Enter the name: ";
	std::cin >> playerName;

	std::string playerRace;
	std::cout << "Enter the race: ";
	std::cin >> playerRace;

	std::cout << "A new " << playerRace << " was born, his name is " << playerName << ". Welcome to this harsh world!\n";

	return 0;
}