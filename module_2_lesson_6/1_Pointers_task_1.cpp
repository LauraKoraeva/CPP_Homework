/*Массивы и Указатели в C++
Урок 6. Указатели*/

//Задача 1

#include <iostream>

void swapPointers (int *ptr_a, int *ptr_b)
{
    std::swap(*ptr_a, *ptr_b);
}
       
       
int main()
{
    int a = 10;
    int b = 20;
   
    int * ptr_a = &a;
    int * ptr_b = &b;
   
    swapPointers(ptr_a, ptr_b);
   
    std::cout << a << " " << b;
   
    return 0;
}


