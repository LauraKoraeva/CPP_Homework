//Урок 2. Знакомство с std::vector v2

//1. Введение в тип vector

//Задание 1

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cout << "Error!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

int main()
{
	std::cout << "Enter the number of elements: ";
	int length;
	std::cin >> length;

	while (!correctInput(length) || length <= 1)
	{
		std::cout << "The number must be an integer and there should be at least 2 elements. Try again: ";
		std::cin >> length;
	}

	std::cout << "Enter " << length << " numbers to find their arithmetic mean.\n";
	std::vector<int> vec(length);
	for (int i = 0; i < length; ++i)
	{
		std::cin >> vec[i];
		while (!correctInput(vec[i]))
		{
			std::cout << "Try again.\n";
			std::cin >> vec[i];
		}
	}

	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += vec[i];
	}

	float mean = (float)sum / length;
	std::cout << "Mean = " << mean << '\n';

	return 0;
}