#include <iostream>
#include <vector>
#include "gameplay.h"




int main()
{
	std::cout << "~~~~~~~~~~GAME~OF~MATCHES~~~~~~~~~~\n\n";
	Gameplay* gameplay = new Gameplay;
    gameplay->playGame();
    delete gameplay;

	return 0;
}