/*Массивы и Указатели в C++
Урок 7. Расширенная работа с функциями*/

//Задача 2

#include <iostream>

void countWays(int place, int &count, int stairs, int pace = 2)
{
	if ((place < 0) || (place > stairs))
		return;
	
	if (place == stairs)
		count = count + 1;

	for (int i = 1; i <= pace; i++)
		countWays(place + i, count, stairs, pace = 2);
}

int main()
{
	std::cout << "How many stairs does the rabbit have to climb? ";
	int stairs;
	std::cin >> stairs;

	int count = 0;
	int place = 0;
	countWays(place, count, stairs);

	std::cout << "The rabbit has " << count << " ways to climb " << stairs << " stairs.";

	return 0;
}
