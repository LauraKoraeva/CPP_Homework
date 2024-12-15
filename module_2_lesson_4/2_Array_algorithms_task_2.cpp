/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

//Задача 2

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = { 2, 7, 11, 15 };
	int result = 9;

	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[i] + vec[j] == result)
				std::cout << vec[i] << " + " << vec[j] << " = " << result;
		}
	}
	
	return 0;
}
