#include "Game.h"
#include <iostream>

Game::Game() : player1(nullptr), player2(nullptr), currentPlayerMark(Board::Player::X) { }

void Game::play() 
{
    int gameMode;
    do
    {
        std::cout << "Select the game mode:\n";
        std::cout << "1 - Human versus Human\n";
        std::cout << "2 - Human versus Computer\n";
        std::cin >> gameMode;
    } while (!correctInput(gameMode));

    initPlayers(gameMode);

    while (!isGameOver()) 
    {
        board.printBoard();
        int move = player1->getMove(board);

        if (isValidMove(move)) 
        {
            board.makeMove(move, player1->getMark());
            switchPlayer();
        } 
        else 
        {
            std::cout << "Incorrect input. Try again.\n";
        }
    }

    board.printBoard();
    printResult();
    cleanupPlayers();
    board.clearBoard();
}

void Game::switchPlayer() 
{
    if (currentPlayerMark == Board::Player::X) 
    {
        currentPlayerMark = Board::Player::O;
        std::swap(player1, player2); 
    } 
    else 
    {
        currentPlayerMark = Board::Player::X;
        std::swap(player1, player2);
    }
}

bool Game::isValidMove(int move) 
{
    return (move >= 0 && move < 9 && board.getCell(move) == Board::Player::NONE);
}

bool Game::isGameOver() 
{
    return (board.getWinner() != Board::Player::NONE || board.isBoardFull());
}

void Game::printResult() 
{
    Board::Player winner = board.getWinner();
    if (winner != Board::Player::NONE) 
    {
        if (winner == Board::Player::X) 
        {
            if (player1->getMark() == Board::Player::X)
                std::cout << "Player 1 won (X)!\n";
            else
                std::cout << "Player 2 won (X)!\n";
        } 
        else 
        {
             if (player1->getMark() == Board::Player::O)
                std::cout << "Player 1 won (O)!\n";
            else
                std::cout << "Player 2 won (O)!\n";
        }
    } 
    else 
    {
        std::cout << "Draw!\n";
    }
}

void Game::initPlayers(int gameMode) 
{
    if (gameMode == 1) 
    {
        player1 = new HumanPlayer(Board::Player::X);
        player2 = new HumanPlayer(Board::Player::O);
    } 
    else 
    {
        player1 = new HumanPlayer(Board::Player::X);
        player2 = new ComputerPlayer(Board::Player::O);
    }
    currentPlayerMark = Board::Player::X; 

}

void Game::cleanupPlayers() 
{
    delete player1;
    delete player2;
    player1 = nullptr;
    player2 = nullptr;
}