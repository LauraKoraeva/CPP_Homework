/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

//Задача 3

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	std::cout << "Enter numbers: ";
	
	int number;
	std::cin >> number;

	while (number != -2)
	{
		if (number != -1)
		{
			vec.push_back(number);
		}
		else
		{
			for (int i = 0; i < vec.size(); ++i)
			{
				for (int j = i + 1; j < vec.size(); ++j)
				{
					if (vec[j] < vec[i])
					{
						std::swap(vec[i], vec[j]);
					}
				}
			}

			std::cout << "The fifth element: " << vec[4] << '\n';
		}

		std::cin >> number;
	}

	return 0;
}

