#pragma once
// #include <iostream>

class Conditions
{
	int playersCount;
	int totalMatches;
	int minMove;
	int maxMove;

public:
	Conditions() : playersCount(2), totalMatches(10), minMove(1), maxMove(2)
	{
	}

	void setConditions();

	int getPlayersCount() const { return playersCount; }
	int getTotalMatches() const { return totalMatches; }
	int getMinMove() const { return minMove; }
	int getMaxMove() const { return maxMove; }

    ~Conditions() { }
};