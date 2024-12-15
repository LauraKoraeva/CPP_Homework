/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

//Задача 4

#include <iostream>
#include <vector>

int main() 
{
	std::vector<int> a = { -100,-50, -5, 1, 10, 15 };

	for (int i = 0; i < a.size(); ++i) 
	{
		for (int j = 0; j < a.size() - i - 1; ++j) 
		{
			int abs_1 = abs(a[j]);
			int abs_2 = abs(a[j + 1]);

			if (abs_1 > abs_2) 
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}

	for (int i = 0; i < a.size(); ++i) 
	{
		std::cout << a[i] << " ";
	}

	return 0;
}