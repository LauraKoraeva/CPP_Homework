/*Массивы и Указатели в C++
Урок 7. Расширенная работа с функциями*/

//Задача 3

#include <iostream>

void evenDigits(long long number, int& ans)
{
	if (number == 0)
		return;

	int digit = number % 10;

	if (digit % 2 == 0)
		++ans;

	number /= 10;

	evenDigits(number, ans);
}

int main()
{
	std::cout << "Enter a number: ";
	long long number;
	std::cin >> number;

	int ans = 0;

	evenDigits(number, ans);

	std::cout << "Even digits: " << ans;

	return 0;
}