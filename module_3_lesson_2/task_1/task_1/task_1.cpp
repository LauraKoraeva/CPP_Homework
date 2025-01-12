// Продвинутые темы и техники C++
// Урок 2. Запись в файлы

// Задание 1. Реализация записи в ведомость учёта

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <numeric>

struct PaymentInfo
{
    std::string name;
    std::string surname;
    std::string date;
    double cash;
    std::string currency = "RUB";
};

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

bool correctDate(std::string& date)
{
    bool correctDate = true;
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));

    if (month > 12)
    {
        std::cout << "Invalid date.Try again\n";
        correctDate = false;
    }
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
    {
        std::cout << "Invalid date.Try again\n";
        correctDate = false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cout << "Invalid date.Try again\n";
        correctDate = false;
    }
    else if (month == 2 && day > 29)
    {
        std::cout << "Invalid date.Try again\n";
        correctDate = false;
    }
    return correctDate;
}

void getInfo(PaymentInfo& payment)
{
    std::cout << "Enter the data:\n";
    std::cout << "Name: ";
    std::cin >> payment.name;
    std::cout << "Surname: ";
    std::cin >> payment.surname;
    do
    {
        std::cout << "Date: ";
        std::cin >> payment.date;
    } while (!correctDate(payment.date));
    do
    {
        std::cout << "Cash: ";
        std::cin >> payment.cash;
    } while (!correctInput(payment.cash));
}

int main()
{
    std::ofstream database("database.txt", std::ios::app);

    database.setf(std::ios::showpoint);
    database.setf(std::ios::fixed);
    database.precision(2);

    PaymentInfo payment;
    getInfo(payment);

    database << payment.name << " " << payment.surname << " " << payment.date << " " << payment.cash << " " << payment.currency << std::endl;

    database.close();

    return 0;
}
