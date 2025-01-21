// Продвинутые темы и техники C++
// Урок 6. Работа с датами 

// Задание 2. Реализация программы напоминания о днях рождения

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <map>
#include <sstream>

struct Birthday
{
    std::string name;
    std::string surname;
    std::tm birthday;
};

int main()
{
    std::vector<Birthday> birthdays;

    while (true)
    {
        Birthday person;
        std::cout << "Enter the name: ";
        std::cin >> person.name;
        if (person.name == "end")
            break;
        std::cout << "Enter the surname: ";
        std::cin >> person.surname;

        std::istringstream ss("");
        do
        {
            std::cout << "Enter the birthday [YYYY/MM/DD]: ";
            std::string inputDate;
            std::cin >> inputDate;
            person.birthday = {};
            std::istringstream ss(inputDate);
            ss >> std::get_time(&person.birthday, "%Y/%m/%d");
            if (ss.fail() || person.birthday.tm_year < 0 || person.birthday.tm_mday == 0)
            {
                std::cerr << "Incorrect input" << std::endl;
            }
        } while (ss.fail() || person.birthday.tm_year < 0 || person.birthday.tm_mday == 0);


        birthdays.push_back(person);
    }

    std::time_t now = std::time(nullptr);
    std::tm* today = std::localtime(&now);

    std::multimap<int, Birthday> sorted;

    for (int i = 0; i < birthdays.size(); ++i)
    {
        if (birthdays[i].birthday.tm_mon >= today->tm_mon)
        {
            birthdays[i].birthday.tm_year = today->tm_year;

            std::time_t b = std::mktime(&birthdays[i].birthday);
            std::time_t t = std::mktime(today);

            int diff = std::difftime(b, t);
            if (diff > 0)
            {
                diff /= (60 * 60 * 24);
                birthdays[i].birthday.tm_mon += 1;
                sorted.insert({ diff, birthdays[i] });
            }
        }
    }
    std::cout << '\n';
    if (!sorted.empty())
    {
        auto it = sorted.equal_range(sorted.begin()->first);

        for (auto itr = it.first; itr != it.second; ++itr)
        {
            std::cout << itr->second.name << " " << itr->second.surname << "\'s birthday is on "
                << std::setw(2) << std::setfill('0') << itr->second.birthday.tm_mon << "/" << itr->second.birthday.tm_mday << '\n';
        }
    }
    else
        std::cout << "No birthdays ahead!\n";

    return 0;
}



