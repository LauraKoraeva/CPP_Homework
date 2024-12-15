/*Основы программирования на C++
Урок 11. Функции в программировании*/

//Задание 2. Проверка корректности email-адреса

#include <iostream>
#include <string>

bool check_at_sign(std::string& email)
{
    int at_count = 0;
    for (int i = 0; i < email.size(); ++i)
    {
        if (email[i] == '@')
        {
            ++at_count;
        }
    }
    if (at_count != 1)
        return false;
    else
        return true;
}

void get_email_parts(std::string email, std::string& part_1, std::string& part_2)
{
    part_1 = email.substr(0, email.find('@'));
    part_2 = email.substr(email.find('@') + 1, email.size());
}

bool check_length(std::string& part_1, std::string& part_2)
{
    if (part_1.size() < 1 || part_1.size() > 64)
        return false;
    if (part_2.size() < 1 || part_2.size() > 63)
        return false;

    return true;
}

bool check_symbols(std::string& email_part)
{
    for (int i = 0; i < email_part.size(); ++i)
    {
        if ((email_part[i] < '0' || email_part[i] > '9') && email_part[i] != '.' && email_part[i] != '-' &&
            (email_part[i] < 'A' || email_part[i] > 'Z') && (email_part[i] < 'a' || email_part[i] > 'z'))
            return false;
    }
    return true;
}

void check_symbols_extra(std::string& email_part)
{
    std::string extra_symbols = "!#$%&'*+-/=?^_{|}~`";
    for (int i = 0; i < email_part.size(); ++i)
    {
        for (int j = 0; j < extra_symbols.size(); ++j)
        {
            if (email_part[i] == extra_symbols[j])
                email_part[i] = '0';
        }
    }
}

bool check_points(std::string& email_part)
{
    if (email_part[0] == '.' || email_part[email_part.size() - 1] == '.')
        return false;

    for (int i = 0; i < email_part.size() - 1; ++i)
    {
        if (email_part[i] == '.' && email_part[i + 1] == '.')
            return false;
    }
    return true;
}

int main()
{
    std::cout << "Enter email address: ";
    std::string email;
    std::cin >> email;
    
    bool isValid = true;

    if (!check_at_sign(email))
        isValid = false;
    else
    {
        std::string part_1, part_2;
        get_email_parts(email, part_1, part_2);

        if (!check_length(part_1, part_2) || !check_points(part_1) || !check_points(part_2))
            isValid = false;
        else
        {
            check_symbols_extra(part_1);

            if (!check_symbols(part_1) || !check_symbols(part_2))
                isValid = false;
        }
    }

    if (isValid)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
   
    return 0;
}
