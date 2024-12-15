/*Массивы и Указатели в C++
Урок 7. Расширенная работа с функциями*/

//Задача 1

#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int* array, int arrayLength)
{
	if (vec.size() == arrayLength)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			std::swap(vec[i], *(array + i));
		}
	}
}

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int array[] = { 6, 7, 8, 9, 10 };
	int arrayLength = sizeof(array) / sizeof(array[0]);
	
	swapvec(vec, array, arrayLength);

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < arrayLength; ++i)
	{
		std::cout << array[i] << " ";
	}

	return 0;
}