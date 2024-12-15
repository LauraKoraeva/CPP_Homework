/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Практическая работа

//Задание 4. Счастливый билетик

#include <iostream>

int main()
{
    std::cout << "Enter the ticket number: ";
    int ticketNumber;
    std::cin >> ticketNumber;

    int tempTicketNumber = ticketNumber;
    int digitCount = 0;
    while (tempTicketNumber != 0)
    {
        tempTicketNumber /= 10;
        ++digitCount;
    }
    if (digitCount % 2 != 0)
        std::cout << "The number of digits in the ticket number must be even.";
    else
    {
        int iterationCount = digitCount / 2;
        int sumRight = 0;
        int sumLeft = 0;
        int countRight = 0;
        int countLeft = 0;
        while (countRight < iterationCount)
        {
            int digit = ticketNumber % 10;
            sumRight = sumRight + digit;
            ticketNumber /= 10;
            ++countRight;
        }
        while (countLeft < iterationCount)
        {
            int digit = ticketNumber % 10;
            sumLeft += digit;
            ticketNumber /= 10;
            ++countLeft;
        }
        if (sumRight == sumLeft)
            std::cout << "The ticket is a lucky one!\n";
        else
            std::cout << "Better luck next time!\n";
    }
    return 0;
}