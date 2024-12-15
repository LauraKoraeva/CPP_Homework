/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Практическая работа

//Задание 3. Игрушечная история

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Find out how many sets of cubes you can make.\n";
    std::cout << "Enter bar's length, width and height:\n";
   
    double length;
    std::cout << "Length: ";
    std::cin >> length;
   
    double width;
    std::cout << "Width: ";
    std::cin >> width;
   
    double height;
    std::cout << "Height: ";
    std::cin >> height;
   
    if (length < 5 || width < 5 || height < 5)
    {
std::cout << "The bar is too small to make a single cube.";
}
else
{
    int x = length / 5;
    int y = width / 5;
    int z = height / 5;
   
    int cubesCount = x * y * z;
    int setsCount = std::pow((int)std::pow(cubesCount, 1.0 / 3), 3);
   
    std::cout << "You can make " << setsCount << " sets out of " << cubesCount << " cubes.\n";
}

    return 0;
}
