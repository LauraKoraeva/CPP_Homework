#include <iostream>
#include "conditions.h"

void Conditions::setConditions()
	{
		std::cout << "Before you start set the conditions.\n\n";
		std::cout << "Number of players: ";
		std::cin >> playersCount;
		std::cout << "Total number of matches: ";
		std::cin >> totalMatches;
		std::cout << "Minimum number of matches that can be drawn in one move: ";
		std::cin >> minMove;
		std::cout << "Maximum number of matches that can be drawn in one move: ";
		std::cin >> maxMove;
	}

    

    Conditions::~Conditions() { }