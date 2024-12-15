//Урок 2. Знакомство с std::vector v2

//1. Введение в тип vector

//Задание 2

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(float input)
{
	if (std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cerr << "Error!\n";
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
		std::cout << "The number must be an integer and there should be at least 2 elements. Try again.\n";
		std::cin >> length;
	}

	std::vector<float> vec(length);
	std::cout << "Enter " << length << " decimal numbers:\n";
	for (int i = 0; i < length; ++i)
	{
		std::cin >> vec[i];
		while (!correctInput(vec[i]))
		{
			std::cout << "Try again.\n";
			std::cin >> vec[i];
		}
	}

	std::cout << "These are the numbers you entered in the opposite order:\n";
	for (int i = length - 1; i >= 0; --i)
	{
		std::cout << vec[i] << " ";
	}

	return 0;
}
