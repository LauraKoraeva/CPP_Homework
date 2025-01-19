// Продвинутые темы и техники C++
// Урок 4. Словари std::map

// Задание 2. Регистратура

#include <iostream>
#include <map>
#include <string>  

int main()
{
    std::map<std::string, int> queue;
    int number = 0;

    std::string query;
    while (query != "-1")
    {
        std::cout << "Enter query: ";
        std::getline(std::cin, query);

        if (query != "Next" && query != "next")
        {
            ++number;
            queue.insert(std::pair<std::string, int>(query, number));
        }
        else
        {
            if (number > 0)
            {
                std::cout << queue.begin()->first << '\n';
                queue.erase(queue.begin()->first);
                --number;
            }
            else
                std::cout << "Queue is empty.\n";
        }
    }
    return 0;
}
