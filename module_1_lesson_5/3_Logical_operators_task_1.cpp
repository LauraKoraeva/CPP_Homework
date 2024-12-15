/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Логические операторы и сложные условия

//Задача 1.

#include <iostream>
#include <cassert>

int main()
{
    std::cout << "Find out the character level in the game!\n";
    int playerLevel = 1;
    int experiencePoints;
    std::cout << "Enter the number of experience points: ";
    std::cin >> experiencePoints;

    std::cout << "-----Calculating-----\n";

    assert(experiencePoints >= 0);

    if (experiencePoints < 1000)
    {
    }
    else if (experiencePoints >= 1000 && experiencePoints < 2500)
    {
        playerLevel = 2;
    }
    else if (experiencePoints >= 2500 && experiencePoints < 5000)
    {
        playerLevel = 3;
    }
    else if (experiencePoints >= 5000)
    {
        playerLevel = 4;
    }
    std::cout << "Your level: " << playerLevel << '\n';

    return 0;
}

