// Продвинутые темы и техники C++
// Урок 2. Запись в файлы

// Задание 3. Реализация симуляции игры «Рыбалка»

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream river;
    river.open("river.txt");

    std::ofstream basket("basket.txt", std::ios::app);

    if (river.is_open() && basket.is_open())
    {
        std::cout << "What kind of fish do you want to catch today? ";
        std::string fish;
        std::getline(std::cin, fish);
        if (fish != "sunfish" && fish != "shad" && fish != "carp" && fish != "bass" && fish != "bullhead" && fish != "catfish" && fish != "walleye")
            std::cout << "Sorry! No such fish in this lake!";
        else
        {
            int countFish = 0;
            std::string fishCaught;
            while (!river.eof())
            {
                river >> fishCaught;
                if (fish == fishCaught)
                {
                    basket << fish << std::endl;
                    ++countFish;
                }
            }
            std::cout << "Congratulations! You've caught " << countFish << " " << fish << " today.";
        }
        river.close();
        basket.close();
    }
    else
        std::cout << "An error has occurred.";

    return 0;
}
