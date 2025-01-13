// Продвинутые темы и техники C++
// Урок 2. Запись в файлы

// Задание 2. Реализация рисования случайных картин

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input <= 0)
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
    std::ofstream picture("pic.txt");

    if (picture.is_open())
    {
        int length;
        int height;
        do
        {
            std::cout << "Enter the length: ";
            std::cin >> length;
        } while (!correctInput(length));
        do
        {
            std::cout << "Enter the height: ";
            std::cin >> height;
        } while (!correctInput(height));

        std::srand(std::time(nullptr));

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < length; ++j)
            {
                int number = rand() % 2;
                picture << number;
            }
            picture << std::endl;
        }
        picture.close();
    }
    else
        std::cout << "An error has occurred.";

    return 0;
}