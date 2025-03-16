#include <iostream>
// #include <vector>
#include "gameplay.h"

int main()
{
	std::cout << "~~~~~~~~~~GAME~OF~MATCHES~~~~~~~~~~\n\n";
	Gameplay* gameplay = new Gameplay;
	std::cout << "============================================\n";
	std::cout << "                 LET'S-PLAY                \n";
	std::cout << "============================================\n";
    gameplay->playGame();
    delete gameplay;

	return 0;
}