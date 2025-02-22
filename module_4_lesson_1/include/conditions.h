#pragma once
#include <iostream>

class Conditions
{
	int playersCount;
	int totalMatches;
	int minMove;
	int maxMove;

public:
	void setConditions();
	int getPlayersCount() { return playersCount; }
	int getTotalMatches() { return totalMatches; }
	int getMinMove() { return minMove; }
	int getMaxMove() { return maxMove; }

    

    ~Conditions();
};