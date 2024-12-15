/*Основы программирования на C++
Урок 2. Целочисленные переменные. Данные и вычисления
*/

//Вывод значений переменных

#include <iostream>

int main()
{
std::string game = "Super Race";
int lap = 4;
std::string driver = "Schumacher";
int engine = 254;
int wheels = 93;
int steeringWheel = 49;
int wind = 21;
int rain = 17;
int speed = 358;

std::cout << "-------------------------\n";
std::cout << game << ". Lap " << lap << "\n";
std::cout << "-------------------------\n";
std::cout << driver << " (" << speed << ")" << '\n';
std::cout << "-------------------------\n";
std::cout << "Driver: " << driver << '\n';
std::cout << "Speed: " << speed << '\n';
std::cout << "---------------\n";
std::cout << "Equipment\n";
std::cout << "Engine: +" << engine << '\n';
std::cout << "Wheels: +" << wheels << '\n';
std::cout << "Steering wheel: +" << steeringWheel << '\n';
std::cout << "---------------\n";
std::cout << "Bad weather conditions\n";
std::cout << "Wind: -" << wind << '\n';
std::cout << "Rain: -" << rain << '\n';
}