#include <iostream>
#include <vector>
#include <string>
#include "players.h"

void Players::setPlayers(int playersCount)
	{
		for (int i = 0; i < playersCount; ++i)
		{
			std::cout << "Player " << i + 1 << ", enter your name: ";
			std::string name;
			std::getline(std::cin, name);
			allPlayers.push_back(name);
		}
	}

	std::string Players::getPlayer(int index)
	{
		if (index < 0 || index >= allPlayers.size())
			return nullptr;
		else
			return allPlayers[index];
	}

	int Players::getAllPlayersSize() { return allPlayers.size(); }