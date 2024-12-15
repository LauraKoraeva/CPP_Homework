//Урок 2. Знакомство с std::vector v2

//5. Практическая работа

//Задача 2

#include <iostream>
#include <vector>

int main()
{
    std::vector<float> prices = { 7.5, 8.25, 9.0, 5.25, 6.5, 10.0 };
    std::vector<int> items = { 1, 2, 2, 4, 7, 5 };

    float sum = 0;
    for (int index = 0; index < items.size(); ++index)
    {
        if (items[index] < prices.size())
            sum += prices[items[index]];
        else
        {
            std::cout << "Couldn't find price for item " << items[index] << ".\n";
            std::cout << "It wasn't included in total sum.\n\n";
        }
    }

    std::cout << "Total sum: " << sum << '\n';

    return 0;
}







