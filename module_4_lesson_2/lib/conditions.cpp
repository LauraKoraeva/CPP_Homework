#include <iostream>
#include <limits>
#include <numeric>
#include "conditions.h"
#include "utility.h"

void Conditions::setConditions()
	{
		std::cout << "Before you start set the conditions.\n\n";
		do
		{
			std::cout << "Number of players (at least 2 players are required): ";
			std::cin >> playersCount;
		} while (!correctInput(playersCount) || playersCount <= 1);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		do
		{
			std::cout << "Total number of matches (at least ten matches are required): ";
			std::cin >> totalMatches;
		} while (!correctInput(totalMatches) || totalMatches < 10);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		do
		{
			std::cout << "Minimum number of matches that can be drawn in one move (from 1 to 5): ";
			std::cin >> minMove;
		} while (!correctInput(minMove) || minMove < 1 || minMove > 5);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		do
		{
			std::cout << "Maximum number of matches that can be drawn in one move (greater than " << minMove << 
				" and less than " << totalMatches << "): ";
			std::cin >> maxMove;
		} while (!correctInput(minMove) || maxMove <= minMove || maxMove > totalMatches);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}
