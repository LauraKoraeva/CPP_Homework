#include "Player.h"

Player::Player(Board::Player mark) : mark(mark) { }

Board::Player Player::getMark() const 
{
    return mark;
}