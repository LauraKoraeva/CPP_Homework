/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

//Задача 1

#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    int maxSum = a[0];
    int sum = 0;
    int i_1, i_2;

    for (int i = 0; i < a.size(); ++i) 
    {
        for (int j = 0; j < a.size() - i; ++j) 
        {
            for (int k = j; k < j + i; ++k) 
            {
                sum += a[k];
            }
            if (sum > maxSum) 
            {
                maxSum = sum;
                i_1 = j;
                i_2 = j + i - 1;
            }
            sum = 0;
        }
    }

    std::cout << i_1 << " " << i_2;

    return 0;
}


