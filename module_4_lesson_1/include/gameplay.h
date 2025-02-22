#pragma once
#include <iostream>
#include <vector>
#include "players.h"
#include "conditions.h"

class Gameplay
{
private:
    int matchesLeft;
    int move;
    Conditions* conditions;
    Players* players;

public:

    Gameplay();

    bool moveAcceptable(int move, int& matchesLeft);

    void drawMatches(int& matchesLeft);

    void announceWinner(std::string player);

    void playGame();
    

    ~Gameplay();

};