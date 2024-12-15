/*Массивы и Указатели в C++
Урок 6. Указатели*/

//Задача 2

#include <iostream>

void reverse(int *ptrArray, int length)
{
    for(int i = 0; i < length / 2; ++i)
    {
       std::swap(ptrArray[i], ptrArray[length - i - 1]);
    }
   
}
 
       
int main()
{
    int length = 10;
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   
   
   
    reverse(array, length);
   
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
   
    return 0;
}

