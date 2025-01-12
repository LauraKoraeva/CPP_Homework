//Задание 2. Реализация рисования случайных картин

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{
    std::ofstream picture("C:\\Users\\Acer\\Desktop\\pic.txt");        //

    int length;
    int height;
    std::cout << "Enter the length: ";
    std::cin >> length;                           //
    std::cout << "Enter the height: ";
    std::cin >> height;                           //

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

    return 0;
}