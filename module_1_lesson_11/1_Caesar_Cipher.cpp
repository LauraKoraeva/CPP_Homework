/*Основы программирования на C++
Урок 11. Функции в программировании*/

//Задание 1. Шифр Цезаря

#include <iostream>
#include <string>

void encrypt_ceasar(std::string& text, int key)
{
    if (key < 0)
    {
        key = 26 - (-key);
    }

    for (int i = 0; i < text.length(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int newIndex = (text[i] - 'A' + key) % 26 + 'A';
            char symbol(newIndex);
            text[i] = symbol;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            int newIndex = (text[i] - 'a' + key) % 26 + 'a';
            char symbol(newIndex);
            text[i] = symbol;
        }
    }
}

void decrypt_ceasar(std::string& text, int key)
{
    encrypt_ceasar(text, (-key));
}

int main()
{
    std::cout << "Input the text:\n";
    std::string text;
    std::getline(std::cin, text);

    std::cout << "Input the key:\n";
    int key;
    std::cin >> key;

    while (key == 0)
    {
        std::cout << "The key cannot be zero. Input the key:\n";
        std::cin >> key;
    }

    encrypt_ceasar(text, key);
    std::cout << "\nencrypted: " << text << '\n';
    decrypt_ceasar(text, key);
    std::cout << "\ndecrypted: " << text << '\n';

    return 0;
}
