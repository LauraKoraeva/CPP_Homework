#include <iostream>
#include <vector>
#include <random>

class TicTacToe
{
public:
    enum class GameMode
    {
        FRIEND = 1,
        COMPUTER,
    };

    enum class Player
    {
        NONE,
        X,
        O,
    };

    TicTacToe(GameMode inMode) : board(9, Player::NONE), currentPlayer(Player::X), mode(inMode) { }
    TicTacToe() : TicTacToe(GameMode::COMPUTER) { }

    bool makeMove(int position, Player player)
    {
        if (position < 0 || position >= 9 || board[position] != Player::NONE)
            return false;

        board[position] = player;
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;

        return true;
    }

    bool makeMove(int position)
    {
        return makeMove(position, currentPlayer);
    }


    Player getWinner() const
    {
        int winningCombinations[8][3] = {
            { 0, 1, 2 },
            { 3, 4, 5 },
            { 6, 7, 8 },

            { 0, 3, 6 },
            { 1, 4, 7 },
            { 2, 5, 8 },

            { 0, 4, 8 },
            { 2, 4, 6 }
        };

        for (int i = 0; i < 8; ++i)
        {
            Player p = board[winningCombinations[i][0]];

            if (p != Player::NONE &&
                p == board[winningCombinations[i][1]] &&
                p == board[winningCombinations[i][2]])
                return p;
        }

        return Player::NONE;
    }



    bool isBoardFull() const
    {
        for (Player cell : board)
        {
            if (cell == Player::NONE)
                return false;
        }
        return true;
    }


    Player getCurrentPlayer() const
    {
        return currentPlayer;
    }


    Player getCell(int position) const
    {
        // if (position < 0 || position >= 9)
        //    std::cerr << "Cell does not exist\n";
        //else
        return board[position];
    }

    void setGameMode(GameMode inMode)
    {
        mode = inMode;
    }

    GameMode getGameMode() const
    {
        return mode;
    }


    void printBoard() const
    {
        for (int i = 0; i < 9; ++i)
        {
            switch (board[i])
            {
            case Player::X: std::cout << "X"; break;
            case Player::O: std::cout << "O"; break;
            case Player::NONE: std::cout << "."; break;
            }
            if ((i + 1) % 3 == 0)
                std::cout << std::endl;
        }
    }


    int findBestMove()
    {
        int bestMove = -1;
        int bestScore = -1000;

        for (int i = 0; i < 9; ++i)
        {
            if (board[i] == Player::NONE)
            {
                TicTacToe tempGame = *this;
                tempGame.makeMove(i, Player::O);

                int moveScore = minimax(tempGame, 0, false);

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMove = i;
                }
            }
        }
        return bestMove;
    }


    private:
        std::vector<Player> board;
        Player currentPlayer;
        GameMode mode;

        int minimax(TicTacToe game, int depth, bool isMaximizing)
        {
            Player winner = game.getWinner();

            if (winner == Player::O)
                return 10;

            if (winner == Player::X)
                return -10;

            if (game.isBoardFull())
                return 0;

            if (isMaximizing)
            {
                int bestScore = -1000;
                for (int i = 0; i < 9; ++i)
                {
                    if (game.getCell(i) == Player::NONE)
                    {
                        TicTacToe tempGame = game;
                        tempGame.makeMove(i, Player::O);
                        int score = minimax(tempGame, depth + 1, false);
                        bestScore = std::max(score, bestScore);
                    }
                }
                return bestScore;
            }
            else
            {
                int bestScore = 1000;
                for (int i = 0; i < 9; ++i)
                {
                    if (game.getCell(i) == Player::NONE)
                    {
                        TicTacToe tempGame = game;
                        tempGame.makeMove(i, Player::X);
                        int score = minimax(tempGame, depth + 1, true);
                        bestScore = std::min(score, bestScore);
                    }
                }
                return bestScore;
            }
        }
};



int main()
{
    TicTacToe game;
    bool gameOver = false;

    int mode;
    std::cout << "Select the game mode:\n";
    std::cout << "1 - play with a friend\n";
    std::cout << "2 - play with the computer\n";
    std::cin >> mode; //

    if (mode == 1)
        game.setGameMode(TicTacToe::GameMode::FRIEND);

    std::string playerOne, playerTwo;

    std::cout << "Player 1, enter your name: ";
    std::cin >> playerOne;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (game.getGameMode() == TicTacToe::GameMode::FRIEND)
    {
        std::cout << "Player 2, enter your name: ";
        std::cin >> playerTwo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (!gameOver)
    {
        game.printBoard();

        int move;
        if (game.getCurrentPlayer() == TicTacToe::Player::X)
        {
            std::cout << playerOne << ", your move [0-8]: ";
            std::cin >> move;   //

            if (!game.makeMove(move))
            {
                std::cout << "Incorrect input. Try again.\n";
                continue; 
            }

        }
        else   
        {
            switch (game.getGameMode())
            {
            case TicTacToe::GameMode::FRIEND:
                std::cout << playerTwo << ", your move [0-8]: ";
                std::cin >> move;   //

                if (!game.makeMove(move))
                {
                    std::cout << "Incorrect input. Try again.\n";
                    continue; // 
                }
                break;
            case TicTacToe::GameMode::COMPUTER:
                std::cout << "Computer's move...\n";
                int computerMove = game.findBestMove();
                if (computerMove != -1)
                {
                    game.makeMove(computerMove, TicTacToe::Player::O);
                }
                else
                {
                    std::cout << "Computer could not make a move. Error.\n";
                    gameOver = true;
                }
                break;
            } 
        }

        TicTacToe::Player winner = game.getWinner();
        if (winner != TicTacToe::Player::NONE) 
        {
            game.printBoard();
            std::cout << "Winner: ";
            if (winner == TicTacToe::Player::X)
                std::cout << playerOne << '\n';
            else 
                switch (game.getGameMode())
                {
                case TicTacToe::GameMode::FRIEND: std::cout << playerTwo << '\n'; break;
                case TicTacToe::GameMode::COMPUTER: std::cout << "Computer\n"; break;
                }
            gameOver = true;
        }
        else if (game.isBoardFull()) 
        {
            game.printBoard();
            std::cout << "Draw!\n";
            gameOver = true;
        }
    }

    return 0;
}