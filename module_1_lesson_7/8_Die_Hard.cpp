/*Основы программирования на C++
Урок 7. Циклы for и алгоритмы на циклах*/

//Варианты цикла for

//Задача 3. Крепкий орешек.
#include <iostream>
#include <string>

int main()
{
    std::string answer;
    int count = 10;
    for (; count >= 1; )
    {
        std::cout << "Do you want to cut the wire? ";
        std::getline(std::cin, answer);

        if (answer == "yes" || answer == "Yes")
        {
            --count;
            break;
        }
        else if (answer == "no" || answer == "No")
        {
            --count;
            if (count != 0)
                std::cout << count << " seconds before the explosion\n";
        }
        else
        { 
            --count;
            std::cout << "Did not get the answer. Repeat please\n";
            std::cout << count << " seconds before the explosion\n";
        }
           
    }
    if (count == 0)
        std::cout << "The bomb exploded.";
    else
        std::cout << "Bomb threat neutralized " << count << " seconds before the explosion.\n";

    return 0;
}