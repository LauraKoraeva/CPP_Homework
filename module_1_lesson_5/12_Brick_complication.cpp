/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Практическая работа

//Задание 5. Усложнение задачи про кирпич

#include <iostream>

int main()
{
    std::cout << "Find out whether the first box fits into the second one.\n";
    std::cout << "Enter length, width and height of the first box:\n";
    int l_1, w_1, h_1;
    std::cin >> l_1 >> w_1 >> h_1;

    while (l_1 <= 0 || w_1 <= 0 || h_1 <= 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> l_1 >> w_1 >> h_1;
    }

    std::cout << "Enter length, width and height of the second box:\n";
    int l_2, w_2, h_2;
    std::cin >> l_2 >> w_2 >> h_2;

    while (l_2 <= 0 || w_2 <= 0 || h_2 <= 0)
    {
        std::cout << "Error! try again.\n";
        std::cin >> l_2 >> w_2 >> h_2;
    }

    if (l_1 <= l_2 && l_1 <= w_2 && l_1 <= h_2 && w_1 <= l_2 && w_1 <= w_2 &&
        w_1 <= h_2 && h_1 <= l_2 && h_1 <= w_2 && h_1 <= h_2)
        std::cout << "The first box fits into the second box.\n";
    else
        std::cout << "The first box does not fit into the second box.\n";

    return 0;
}