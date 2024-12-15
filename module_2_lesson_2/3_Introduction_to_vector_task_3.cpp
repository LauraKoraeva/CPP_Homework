//Урок 2. Знакомство с std::vector v2

//1. Введение в тип vector

//Задание 3

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
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

	std::vector<int> vec(length);
	std::cout << "Enter " << length << " numbers:\n";
	for (int i = 0; i < length; ++i)
	{
		std::cin >> vec[i];
		while (!correctInput(vec[i]))
		{
			std::cout << "Try again.\n";
			std::cin >> vec[i];
		}
	}


	for (int outer = 0; outer < 2; ++outer)

	{
		int max = outer;
		for (int inner = outer; inner < length; ++inner)
		{
			if (vec[inner] > vec[max])
				max = inner;
		}
		std::swap(vec[outer], vec[max]);
	}

	std::cout << "The second max element you entered: " << vec[1];

	return 0;
}