/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Практическая работа

//Задача 1. Симулятор маршрутки

#include <iostream>
#include <string>

int main()
{
	int passengers = 0;
	int passengersOn;
	int passengersOff;
	std::string busStop1 = "\"Programmers Street\"";
	std::string busStop2 = "\"Algorithms Avenue\"";
	std::string busStop3 = "\"Stroustrup Street\"";
	std::string busStop4 = "\"Torvalds Street\"";
	int revenue = 0;
	int fare = 20;

	std::cout << "We are arriving at the " << busStop1 << " bus stop. Passengers in the bus: " << passengers << '\n';
	std::cout << "How many passengers got off at the bus stop? ";
	std::cin >> passengersOff;
	std::cout << "How many passengers got on?  ";
	std::cin >> passengersOn;
	passengers = passengers + passengersOn - passengersOff;
	revenue = revenue + (passengersOn * fare);
	std::cout << "We are leaving " << busStop1 << " bus stop. Passengers in the bus: " << passengers << '\n';

	std::cout << "We are arriving at the " << busStop2 << " bus stop. Passengers in the bus: " << passengers << '\n';
	std::cout << "How many passengers got off at the bus stop? ";
	std::cin >> passengersOff;
	std::cout << "How many passengers got on?  ";
	std::cin >> passengersOn;
	passengers = passengers + passengersOn - passengersOff;
	revenue = revenue + (passengersOn * fare);
	std::cout << "We are leaving " << busStop2 << " bus stop. Passengers in the bus: " << passengers << '\n';

	std::cout << "We are arriving at the " << busStop3 << " bus stop. Passengers in the bus: " << passengers << '\n';
	std::cout << "How many passengers got off at the bus stop? ";
	std::cin >> passengersOff;
	std::cout << "How many passengers got on?  ";
	std::cin >> passengersOn;
	passengers = passengers + passengersOn - passengersOff;
	revenue = revenue + (passengersOn * fare);
	std::cout << "We are leaving " << busStop3 << " bus stop. Passengers in the bus: " << passengers << '\n';

	std::cout << "We are arriving at the " << busStop4 << " bus stop. Passengers in the bus: " << passengers << '\n';
	std::cout << "How many passengers got off at the bus stop? ";
	std::cin >> passengersOff;
	std::cout << "How many passengers got on?  ";
	std::cin >> passengersOn;
	passengers = passengers + passengersOn - passengersOff;
	revenue = revenue + (passengersOn * fare);
	std::cout << "We are leaving " << busStop4 << " bus stop. Passengers in the bus: " << passengers << '\n';

	int driverWage = revenue / 4;
	int fuel = revenue / 5;
	int tax = revenue / 5;
	int carMaintenance = revenue / 5;
	int income = revenue - driverWage - fuel - tax - carMaintenance;

	std::cout << "-------------------------\n";
	std::cout << "Revenue: " << revenue << '\n';
	std::cout << "Driver's wage: " << driverWage << '\n';
	std::cout << "Fuel costs: " << fuel << '\n';
	std::cout << "Taxes: " << tax << '\n';
	std::cout << "Car Maintenance costs: " << carMaintenance << '\n';
	std::cout << "Income: " << income << '\n';

	return 0;

}