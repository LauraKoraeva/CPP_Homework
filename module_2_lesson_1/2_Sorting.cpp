/*Массивы и Указатели в C++
Урок 1. Одномерные массивы. Базовые алгоритмы на массивах*/

//Задание 2. Сортировка

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(float input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

void heapify(float array[], int length, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < length && array[left] < array[smallest])
    {
        smallest = left;
    }

    if (right < length && array[right] < array[smallest])
    {
        smallest = right;
    }

    if (smallest != root)
    {
        std::swap(array[root], array[smallest]);
        heapify(array, length, smallest);
    }
}

void heapSort(float array[], int length)
{
    for (int root = length / 2 - 1; root >= 0; --root)
    {
        heapify(array, length, root);
    }

    for (int index = length - 1; index >= 0; --index)
    {
        std::swap(array[0], array[index]);
        heapify(array, index, 0);
    }
}

void printArray(float array[], int length)
{
    for (int count = 0; count < length; ++count)
    {
        std::cout << array[count] << " ";
    }
}

int main()
{
    const int length = 15;
    float array[length];
    std::cout << "Enter 15 decimal numbers:\n";
    for (int count = 0; count < 15; ++count)
    {
        do
        {
            std::cin >> array[count];
        } while (!correctInput(array[count]));
        
    }

    heapSort(array, length);

    printArray(array, length);
}