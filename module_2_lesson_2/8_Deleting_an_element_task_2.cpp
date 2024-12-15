//Урок 2. Знакомство с std::vector v2

//3. Удаление элемента со сдвигом

//Задание 2

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

std::vector<int> changeDisplay(std::vector<int> display, int action, int number)
{
	if (action == 1)
	{
		display.resize(display.size() + 1);
		display[display.size() - 1] = number;
		std::cout << "Added one robot.\n";
	}

	if (action == 2)
	{
		std::vector<int> newDisplay(display.size() - 1);
		for (int index = 0; index < display.size(); ++index)
		{
			if (index < number)
				newDisplay[index] = display[index];
			else if (index > number)
				newDisplay[index - 1] = display[index];
		}
		display = newDisplay;
		std::cout << "Removed one robot.\n";
	}

	return display;
}

int main()
{
	std::vector<int> display;

	std::cout << "Enter the number of required actions: ";
	int actionsCount;
	std::cin >> actionsCount;
	while (!correctInput(actionsCount) || actionsCount < 0)
	{
		std::cout << "Incorrect input. Try again: ";
		std::cin >> actionsCount;
	}

	std::cout << "-----------------------------------\n";
	std::cout << "1 - add a robot to the display\n";
	std::cout << "2 - remove a robot from the display\n";
	std::cout << "-----------------------------------\n";

	int index = 1;
	while (index <= actionsCount)
	{
		std::cout << "#" << index << ". Enter required action and number [action number]: ";
		int action;
		int number;
		std::cin >> action >> number;

		while (!correctInput(action) || !correctInput(number) || action < 1 || action > 2 || number < 0)
		{
			std::cout << "Incorrect input. Try again: ";
			std::cin >> action >> number;
		}

		while (action == 2 && number > display.size() - 1)
		{
			std::cout << "No such robot. Try again: ";
			std::cin >> action >> number;
		}
		
		display = changeDisplay(display, action, number);

		++index;
	}

	std::cout << "\n*****DISPLAY*****\n\n";
	for (int index = 0; index < display.size(); ++index)
		std::cout << display[index] << " ";
	std::cout << "\n*****************";

	return 0;
}

