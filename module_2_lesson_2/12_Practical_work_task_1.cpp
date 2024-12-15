//Урок 2. Знакомство с std::vector v2

//5. Практическая работа

//Задача 1

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
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

int main()
{
    int size = 0;
    do
    {
        std::cout << "Input vector size: ";
        std::cin >> size;
        if (size < 0)
            std::cout << "Incorrect input.\n";
        
    } while (!correctInput(size) || size <= 0);
    std::vector<int> vec(size);
    
    std::cout << "Input " << size << " numbers:\n";
    for (int index = 0; index < size; ++index)
    {
        do
        {
            std::cout << "Number #" << index + 1 << ": ";
            std::cin >> vec[index];
        } while (!correctInput(vec[index]));
    }

    int numberToDelete = 0;
    do
    {
        std::cout << "Input number to delete: ";
        std::cin >> numberToDelete;
    } while (!correctInput(numberToDelete));

    for (int outerIndex = 0; outerIndex < vec.size(); ++outerIndex)
    {
        if (vec[outerIndex] == numberToDelete)
        {
            for (int innerIndex = outerIndex; innerIndex < vec.size() - 1; ++innerIndex)
            {
                std::swap(vec[innerIndex], vec[innerIndex + 1]);
            }
            vec.pop_back();
            --outerIndex;
        }
    }

    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";

    return 0;
}

