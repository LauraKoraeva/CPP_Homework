//Урок 2. Знакомство с std::vector v2

//2. Добавление элемента в конец вектора

//Задание 2. Лечебница

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n' || input < 0)
	{
		std::cerr << "Incorrect input\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

std::vector<int> add(std::vector<int> ageData, int number)
{
	std::vector<int> newAgeData(ageData.size() + 1);

	for (int index = 0; index < ageData.size(); ++index)
		newAgeData[index] = ageData[index];
	newAgeData[ageData.size()] = number;

	return newAgeData;
}

int main()
{
	std::vector<int> ageData;

	int patientsCount = 0;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Please enter patient's age: ";
		std::cin >> number;
		if (correctInput(number))
		{
			++patientsCount;
			ageData = add(ageData, number);
		}
	}

	float sum = 0;
	for (int index = 0; index < ageData.size(); ++index)
	{
		sum += ageData[index];
	}

	float meanAge = sum / patientsCount;

	std::cout << "Number of patients: " << patientsCount << '\n';
	std::cout << "Patients' average age: " << meanAge << '\n';

	return 0;
}
