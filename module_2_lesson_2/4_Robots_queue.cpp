//Урок 2. Знакомство с std::vector v2

//2. Добавление элемента в конец вектора

//Задание 1. Очередь из роботов

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cerr << "Incorrect input\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

std::vector<int> add(std::vector<int> queue, int number)
{
	std::vector<int> newQueue(queue.size() + 1);

	for (int index = 0; index < queue.size(); ++index)
		newQueue[index] = queue[index];
	newQueue[queue.size()] = number;

	return newQueue;
}

int main()
{
	std::vector<int> queue;

	int number = 0;
	while (!(number < 0))
	{
		std::cout << "Please enter your number: ";
		std::cin >> number;
		if (correctInput(number))
			queue = add(queue, number);
	}

	for (int index = 0; index < queue.size(); ++index)
	{
		if (queue[index] >= 0)
			std::cout << queue[index] << " ";
	}

	return 0;
}

