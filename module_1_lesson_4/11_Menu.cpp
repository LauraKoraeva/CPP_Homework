/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Практическая работа

//Задание 7. Меню ресторана

#include <iostream>
#include <string>

int main()
{
    std::cout << "*****Business-lunch*****\n";
    std::cout << "See the menu for today!\n";
    std::cout << "Enter the day of the week (from 1 to 7): ";
    int day;
    std::cin >> day;

    while (day < 1 || day > 7)
    {
        std::cout << "Error! Try again.\n";
        std::cin >> day;
    }

    std::string drink = "Drink (tea, coffee, mors)";

    std::string firstDish1 = "Chicken noodle soup";
    std::string mainDish1 = "Turkey meatballs with vegetables";

    std::string firstDish2 = "Fish solyanka";
    std::string mainDish2 = "Pike perch in sour cream sauce with mashed potatoes";

    std::string firstDish3 = "Cabbage soup with beef";
    std::string mainDish3 = "Beef goulash and buckwheat with onions";

    std::string firstDish4 = "The Volga ukha";
    std::string mainDish4 = "Perch fillet with bulgur and zucchini";

    std::string firstDish5 = "Minestrone with chicken meatballs";
    std::string mainDish5 = "Chicken kebab with rice and white wine sauce";

    std::string firstDish6 = "Tom yam with rice";
    std::string mainDish6 = "Crab patties with mashed potatoes";

    std::string firstDish7 = "Sorrel soup with chicken and egg";
    std::string mainDish7 = "Beef cabbage roll with sour cream";

    if (day == 1)
    {
        std::cout << "Today's menu (Monday):\n";
        std::cout << firstDish1 << '\n';
        std::cout << mainDish1 << '\n';
    }

    if (day == 2)
    {
        std::cout << "Today's menu (Tuesday):\n";
        std::cout << firstDish2 << '\n';
        std::cout << mainDish2 << '\n';
    }

    if (day == 3)
    {
        std::cout << "Today's menu (Wednesday):\n";
        std::cout << firstDish3 << '\n';
        std::cout << mainDish3 << '\n';
    }

    if (day == 4)
    {
        std::cout << "Today's menu (Thursday):\n";
        std::cout << firstDish4 << '\n';
        std::cout << mainDish4 << '\n';
    }

    if (day == 5)
    {
        std::cout << "Today's menu (Friday):\n";
        std::cout << firstDish5 << '\n';
        std::cout << mainDish5 << '\n';
    }

    if (day == 6)
    {
        std::cout << "Today's menu (Saturday):\n";
        std::cout << firstDish6 << '\n';
        std::cout << mainDish6 << '\n';
    }

    if (day == 7)
    {
        std::cout << "Today's menu (Sunday):\n";
        std::cout << firstDish7 << '\n';
        std::cout << mainDish7 << '\n';
    }
    std::cout << drink << '\n';

    return 0;
}