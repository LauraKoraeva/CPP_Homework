//Урок 2. Знакомство с std::vector v2

//2. Добавление элемента в конец вектора

//Задание 3. Роботы и коррупция*

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

std::vector<int> addToPosition(std::vector<int> queue, int number, int position)
{
	std::vector<int> newQueue(queue.size() + 1);

	if (position <= queue.size())
	{
		for (int index = 0; index <= queue.size(); ++index)
			if (index < position - 1)
				newQueue[index] = queue[index];
			else if (index > position - 1)
				newQueue[index] = queue[index - 1];
			else if (index == position - 1)
				newQueue[index] = number;
	}
	else if (position > queue.size())
	{
		for (int index = 0; index < queue.size(); ++index)
			newQueue[index] = queue[index];
		newQueue[queue.size()] = number;
	}

	return newQueue;
}

int main()
{
	std::vector<int> queue;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Please enter your number: ";
		std::cin >> number;
		
		while (!correctInput(number) || number < -1)
		{
			std::cout << "Incorrect input. Enter your number again: ";
			std::cin >> number;
		}
		
		if (number != -1)
		{
			std::cout << "Enter your position: ";
			int position;
			std::cin >> position;

			while (!correctInput(position) || position <= 0)
			{
				std::cout << "Incorrect input. Enter your position again: ";
				std::cin >> position;
			}

			queue = addToPosition(queue, number, position);
		}
	}

	for (int index = 0; index < queue.size(); ++index)
	{
		if (queue[index] > 0)
			std::cout << queue[index] << " ";
	}

	return 0;
}