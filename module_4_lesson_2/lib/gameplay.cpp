#include <iostream>
#include "gameplay.h"
#include "conditions.h"
#include "players.h"

Gameplay::Gameplay()
    {
        conditions = new Conditions;
        conditions->setConditions();
		players = new Players;
        players->setPlayers(conditions->getPlayersCount());
    }

    bool Gameplay::moveAcceptable(int move, int& matchesLeft)
    {
		if (move <= matchesLeft && move >= conditions->getMinMove() && move <= conditions->getMaxMove())
		    return true;
	    else if (move > matchesLeft)
	    {
		    std::cout << "Too many. Try again!\n";
		    return false;
	    }
	    else if (move < conditions->getMinMove() || move > conditions->getMaxMove())
	    {
		    std::cout << "You can only draw " << conditions->getMinMove() << " to " << conditions->getMaxMove() << " matches. Try again!\n";
		    return false;
	    }
    }

    void Gameplay::drawMatches(int& matchesLeft)
    {
	    int move;
	    do
	    {
		    std::cout << "How many matches do you want to draw? ";
		    std::cin >> move;
	    } while (!moveAcceptable(move, matchesLeft));
	    matchesLeft -= move;
    }

    void Gameplay::announceWinner(std::string player)
    {
	    std::cout << "\n********************************************\n";
	    std::cout << player << ", congratulations! You won!\n";
    }

    void Gameplay::playGame()
    {
	    bool haveWinner = false;
        matchesLeft = conditions->getTotalMatches();
	    while (!haveWinner)
	    {
		    for (int i = 0; i < players->getAllPlayersSize(); ++i)
		    {
			    std::cout << "--------------------------------------------\n";
			    std::cout << "Matches left: " << matchesLeft << '\n';
			    std::cout << "--------------------------------------------\n";
				if (matchesLeft < conditions->getMinMove())
				{
					std::cout << "Few matches left in the game. You win.\n";
					matchesLeft = 0;
				}
				else
			    {
					std::cout << players->getPlayer(i) << ", make your move.\n";
			    	drawMatches(matchesLeft);
				}
			    if (matchesLeft == 0)
			    {
				    haveWinner = true;
				    announceWinner(players->getPlayer(i));
				    break;
			    }
		    }
		    if (haveWinner)
			    break;
	    }
    }
    
    Gameplay::~Gameplay()
    {
        delete conditions;
        delete players;
    }