/*Основы программирования на C++
Урок 9. Строки и текстовые данные. Базовые алгоритмы со строками*/

//Задача 2

#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::getline(std::cin, text);
    std::string word;

    int pos = 0;
    for (int i = 1; i < text.length(); ++i)
    {
        if (text[pos] == text[i])
        {
            word += text[i];
            ++pos;
        }
        else
        {
            pos = 0;
            word = "";
        }
    }

    std::cout << word << '\n';
    
    bool isRepeated = true;

    if (!word.empty())
    {
        for (int i = 0, j = 0; i < text.length(); ++i, ++j)
        {
            if (j == word.length())
                j = 0;
            else
            {
                if (text[i] != word[j])
                {
                    isRepeated = false;
                    break;
                }
            }
        }
    }

    if (!word.empty() && isRepeated)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}


