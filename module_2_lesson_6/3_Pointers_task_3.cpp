/*Массивы и Указатели в C++
Урок 6. Указатели*/

//Задача 3

#include <iostream>
#include <cstring>

bool substr(const char* text, const char* subText)
{
    bool found = false;
    if (std::strstr(text, subText))
        found = true;

    return found;
}

int main()
{
    const char* a = "Hello, world!";
    const char* b = "world";
    const char* c = "friend";

    std::cout << std::boolalpha;
    std::cout << substr(a, b) << " " << substr(a, c);

    return 0;
}