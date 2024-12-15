/*Основы программирования на C++
Урок 11. Функции в программировании*/

//Задание 3. Валидация IP-адреса

#include <iostream>
#include <string>

bool check_length(std::string ip)
{
    int points = 0;
    int symbols = 0;
    for (int i = 0; i < ip.size(); ++i)
    {
        if (ip[i] == '.')
            ++points;
        else
            ++symbols;
    }

    if ((points > 3 || points < 3) || (symbols + points > 15 || symbols + points < 7))
        return false;
    else
        return true;
}

bool check_symbols(std::string ip)
{
    for (int i = 0; i < ip.size(); ++i)
    {
        if ((ip[i] < '0' || ip[i] > '9') && ip[i] != '.')
            return false;
    }
    return true;
}

bool check_points(std::string ip)
{
    if (ip[0] == '.' || ip[ip.size() - 1] == '.')
        return false;
   
    for (int i = 0; i < ip.size() - 1; ++i)
    {
        if (ip[i] == '.' && ip[i + 1] == '.')
            return false;
    }
    return true;
}

bool check_zeros(std::string ip)
{
    for (int i = 0; i < ip.size() - 2; ++i)
    {
        if (ip[i] == '.' && ip[i + 1] == '0' && ip[i + 2] != '.')
            return false;
    }
    return true;
}

int get_address_part(std::string ip, int count)
{
    std::string octa;
    int octaNumber;
    int pointIndex;
    int countPoint = 0;

    if (count == 0)
        octa = ip.substr(0, ip.find('.'));
    else
    {
        for (int i = 0; i < ip.size(); ++i)
        {
            if (ip[i] == '.')
            {
                pointIndex = i;
                ++countPoint;
                if (countPoint == count)
                    octa = ip.substr(pointIndex + 1, ip.find('.'));
            }
        }
    }
    octaNumber = stoi(octa);

    return octaNumber;
}

bool check_range(std::string ip)
{
    for (int count = 0; count < 4; ++count)
    {
        int octaNumber = get_address_part(ip, count);
        if (octaNumber < 0 || octaNumber > 255)
            return false;
    }
    return true;
}

int main()
{
    std::cout << "Enter IP address: ";
    std::string ip;
    std::cin >> ip;

    if (check_length(ip) && check_symbols(ip) && check_points(ip) && check_zeros(ip))
    {
        if (!check_range(ip))
            std::cout << "Invalid\n";
        else
            std::cout << "Valid\n";
    }
    else
        std::cout << "Invalid\n";

    return 0;
}

