/*Массивы и Указатели в C++
Урок 4. Алгоритмы на массивах*/

// Задача 2

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 2, 7, 11, 15 };
    int result = 9;

    bool found = false;
    for (int i = 0; i < vec.size() - 1; ++i) 
    {
        for (int j = i + 1; j < vec.size(); ++j) 
        {
            if (vec[i] + vec[j] == result) 
            {
                printf("%d + %d = %d\n", vec[i], vec[j], result);
                found = true;
                break;
            }
        }
        if (found == true)
            break;
    }

    return 0;
}
