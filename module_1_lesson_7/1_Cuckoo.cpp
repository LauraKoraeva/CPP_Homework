//Урок 2. Знакомство с std::vector v2

//4. Использование push_back()

//Задание 3 (вариант 1)

#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input < -1)
    {
        std::cerr << "Incorrect input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

int getNumber()
{
    int number;
    do
    {
        std::cout << "Please enter your number: ";
        std::cin >> number;
    } while (!correctInput(number));

    return number;
}

void print(std::vector<int> vec)
{
    for (int index = 0; index < vec.size(); ++index)
    {
        if (vec[index] >= 0)
            std::cout << vec[index] << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> room_1;
    std::vector<int> room_2;
    room_1.reserve(10);
    room_2.reserve(20);

    int seatsLeft_1 = 10;
    int seatsLeft_2 = 20;

    int number = 0;
    while (number != -1)
    {
        number = getNumber();
        if (seatsLeft_1 != 0)
        {
            room_1.push_back(number);
            --seatsLeft_1;
            if (seatsLeft_1 == 2)
                std::cout << "Only 2 seats left in Room 1.\n";
        }
        else if (seatsLeft_1 == 0 && seatsLeft_2 != 0)
        {
            if (room_1.size() != 0)
            {
                room_2.resize(room_1.size());
                for (int index = 0; index < room_1.size(); ++index)
                {
                    if (index < room_2.size())
                    {
                        room_2[index] = room_1[index];
                    }
                    --seatsLeft_2;
                }
                room_1.clear();
            }

            room_2.push_back(number);
            --seatsLeft_2;
            if (seatsLeft_2 == 2)
                std::cout << "Only 2 seats left in Room 2.\n";
        }

        if (seatsLeft_1 == 0 && seatsLeft_2 == 0)
        {
            std::cout << "No more seats left.\n";
            break;
        }
    }

    if (room_1.size() != 0)
        print(room_1);
    if (room_2.size() != 0)
        print(room_2);

    return 0;
}
