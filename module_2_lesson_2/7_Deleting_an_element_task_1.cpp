//Урок 2. Знакомство с std::vector v2

//3. Удаление элемента со сдвигом

//Задание 1

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

std::vector<int> changeDisplay(std::vector<int> display, int robotRequired)
{
	std::vector<int> newDisplay(display.size() - 1);
	for (int index = 0; index < display.size(); ++index)
	{
		if (index < robotRequired)
			newDisplay[index] = display[index];
		else if (index > robotRequired)
			newDisplay[index - 1] = display[index];
	}

	return newDisplay;
}

int main()
{
	std::cout << "How many robots are there on the display: ";
	int robotsCount;
	std::cin >> robotsCount;

	while (!correctInput(robotsCount) || robotsCount < 1)
	{
		std::cout << "Error! There has to be at least one robot. Try again: ";
		std::cin >> robotsCount;
	}

	std::vector<int> display(robotsCount);

	std::cout << "Enter robots' numbers:\n";
	for (int index = 0; index < robotsCount; ++index)
	{
		std::cout << "#" << index + 1 << ": ";
		std::cin >> display[index];
		while (!correctInput(display[index]) || display[index] < 0)
		{
			std::cout << "Incorrect input. Try again: ";
			std::cin >> display[index];
		}
	}

	int index = 0;
	while (index < display.size())
	{
		for (int index = 0; index < display.size(); ++index)
			std::cout << display[index] << " ";

		std::cout << "\nWhich robot is required? ";
		int robotRequired;
		std::cin >> robotRequired;

		if (correctInput(robotRequired))
		{
			if (robotRequired < 0 || robotRequired >= display.size())
				std::cout << "No such robot!\n";
			else
				display = changeDisplay(display, robotRequired);


			if (display.size() == 0)
				std::cout << "No robots left!\n";
			else
				std::cout << "Robots left: ";
		}
		else
			std::cout << "Incorrect input. Try again!\n";
	}

	return 0;
}

