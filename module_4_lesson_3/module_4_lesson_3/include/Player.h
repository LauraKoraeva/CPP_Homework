#pragma once

#include "Board.h"

class Player 
{
protected:
    Board::Player mark;

public:
    Player(Board::Player mark);
    virtual int getMove(const Board& board) = 0; 
    Board::Player getMark() const;
};
