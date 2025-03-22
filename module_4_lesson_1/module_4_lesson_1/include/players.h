#pragma once
// #include <iostream>
#include <vector>

class Players
{
private:
	std::vector<std::string> allPlayers;

public:
    void setPlayers(int playersCount);

	std::string getPlayer(int index);

	int getAllPlayersSize();

	~Players() { }
};