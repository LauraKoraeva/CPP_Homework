//Урок 2. Знакомство с std::vector v2

//4. Использование push_back()

//Задание 2

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input < -1)
    {
        std::cerr << "Incorrect input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

int getNumber()
{
    int number;
    do
    {
        std::cout << "Enter your number: ";
        std::cin >> number;
    } while (!correctInput(number));

    return number;
}

int main()
{
    std::vector<int> queue;

    int number = 0;
    while (number != -1)
    {
        number = getNumber();
        while (!queue.empty() && queue[queue.size() - 1] < number)
        {
            queue.pop_back();
        }

        queue.push_back(number);
    }

    for (int index = 0; index < queue.size(); ++index)
        std::cout << queue[index] << " ";

    return 0;
}




