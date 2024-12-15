//Урок 2. Знакомство с std::vector v2

//5. Практическая работа

//Задача 3

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
    int size = 20;
    std::vector<int> vec(size);

    int head = -1;
    bool overWritten = false;

    int number = 0;
    while (true)
    {
        do
        {
            std::cout << "Input number: ";
            std::cin >> number;
        } while (!correctInput(number));

        if (number != -1)
        {
            ++head;
            if (head == size)
            {
                head = 0;
                overWritten = true;
            }
            vec[head] = number;
        }
        else if (number == -1)
        {
            if (overWritten)
            {
                if (head != 0)
                {
                    for (int i = head + 1; i < vec.size(); ++i)
                        std::cout << vec[i] << " ";
                    for (int i = 0; i < head + 1; ++i)
                        std::cout << vec[i] << " ";
                    std::cout << '\n';
                }
                else
                {
                    for (int i = 0; i < vec.size(); ++i)
                        std::cout << vec[i] << " ";
                    std::cout << '\n';
                }
            }
            else
            {
                for (int i = 0; i <= head; ++i)
                    std::cout << vec[i] << " ";
                std::cout << '\n';
            }
        }
    }

    return 0;
}