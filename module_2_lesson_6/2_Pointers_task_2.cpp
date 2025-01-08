/*Массивы и Указатели в C++
Урок 6. Указатели*/

//Задача 2

#include <iostream>

void reverse(int* ptrArray, int length)
{
    std::reverse(ptrArray, ptrArray + length);
}

int main()
{
    int length = 10;
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    reverse(array, length);

    for (const auto& el : array)
        std::cout << el << " ";
    std::cout << '\n';

    return 0;
}
