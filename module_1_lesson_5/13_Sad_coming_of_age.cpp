/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Практическая работа

//Задание 6. Грустное совершеннолетие

#include <iostream>

int main()
{
    int day;
    int month;
    int year;
    std::cout << "Enter today's date [dd mm yyyy]:\n";
    std::cin >> day;
    std::cin >> month;
    std::cin >> year;
   
    int birthDay;
    int birthMonth;
    int birthYear;
    std::cout << "Enter customer's birthday [dd mm yyyy]:\n";
    std::cin >> birthDay;
    std::cin >> birthMonth;
    std::cin >> birthYear;
   
    int age = year - birthYear;
   
    if ((age > 18) || (age == 18 && month > birthMonth) || (age == 18 && month == birthMonth && day > birthDay))
        std::cout << "You can sell beer to this customer.\n";
    else
        std::cout << "You can't sell beer to this customer.\n";
       
    return 0;
}