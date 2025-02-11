#include <iostream> 
#include <iomanip> 
#include <map> 
#include <limits>
#include "player.h"
#include "utility.h"

int main()
{
    Player session;
    session.addPlaylist();
    session.showMenu();

    int operation;
    while (true)
    {
        do
        {
            std::cout << "Choose the operation: ";
            std::cin >> operation;
        } while (!correctInput(operation));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (operation)
        {
        case session.PLAY:
            session.play(session);
            break;
        case session.PAUSE:
            session.pause();
            break;
        case session.STOP:
            session.stop();
            break;
        case session.NEXT:
            session.next();
            break;
        case session.ADD_NEW_TRACK:
            session.addNewTrack();
            break;
        case session.SHOW_MENU:
            session.showMenu();
            break;
        case session.EXIT:
            return 0;
        default:
            std::cout << "No such operation.\n";
        }
    }
}