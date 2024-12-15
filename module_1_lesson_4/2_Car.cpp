/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Задача 2. Автомобиль.

#include <iostream>

int main()
{
    int speedKmph;
    std::cout << "Enter the vehicle speed: ";
    std::cin >> speedKmph;

    while (speedKmph < 0)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> speedKmph;
    }

    int targetDistanceKm = 200;
    int timeH = 2;
    int travelledDistanceKm = speedKmph * timeH;

    if (travelledDistanceKm >= targetDistanceKm)
    {
        std::cout << "You have arrived!" << '\n';
        std::cout << "Welcome to Ryazan!" << '\n';
    }
    else
    {
        int distanceLeftKm = targetDistanceKm - travelledDistanceKm;
        std::cout << distanceLeftKm << " km to Ryazan.\n";
    }

    return 0;
}