/*Основы программирования на C++
Урок 8. Числа с плавающей запятой. Математические вычисления*/

//Практическая работа

//Задание 6. Маятник

#include <iostream>

int main()
{
    float initialAmplitude;
    float finalAmplitude;
   
    do
    {
        std::cout << "Enter the initial amplitude: ";
        std::cin >> initialAmplitude;
        std::cout << "Enter the final amplitude: ";
        std::cin >> finalAmplitude;
       
        if (initialAmplitude < 0 || finalAmplitude < 0 || finalAmplitude > initialAmplitude)
            std::cout << "Error! Try again:\n";
    } while (initialAmplitude < 0 || finalAmplitude < 0 || finalAmplitude > initialAmplitude);
   
    int count = 0;
    while (initialAmplitude > finalAmplitude)
    {
        initialAmplitude *= 1 - 0.084f;
        ++count;
    }
   
    std::cout << "The pendulum will reach the final amplitude after " << count << " oscillations.\n";
   
    return 0;
       
}