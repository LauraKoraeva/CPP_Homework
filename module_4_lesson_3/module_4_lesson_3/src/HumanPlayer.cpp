#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(Board::Player mark) : Player(mark) { }

int HumanPlayer::getMove(const Board& board) 
{
    int move;
    std::cout << "Your move (0-8): ";
    std::cin >> move;
    return move;
}