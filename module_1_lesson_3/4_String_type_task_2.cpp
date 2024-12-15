/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Строковый тип данных

//Задание 2

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter login: ";
    std::string login;
    std::cin >> login;

    std::cout << "Enter password: ";
    std::string password;
    std::cin >> password;

    std::cout << login << ", you have successfully logged in!";

    return 0;
}