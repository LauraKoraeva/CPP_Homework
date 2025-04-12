#include <iostream>
#include <string>
#include "UI.h"
#include "Session.h"
// #include "Config.h"

UI::UI(Timer& inTimer, Statistics& inStatistics) : timer(inTimer), statistics(inStatistics) { }



void UI::displayMenu() 
{
    std::cout << "======Focus=Timer======\n";
    std::cout << "1. Start focus session\n";
    std::cout << "2. Pause focus session\n"; 
    std::cout << "3. Resume focus session\n";   
    std::cout << "4. Stop focus session\n";   
    std::cout << "5. Show statistics\n";  
    std::cout << "6. Exit\n";     
    std::cout << "=======================\n";
}




void UI::startFocusSession()
{
    if (timer.is_Running())
    {
        std::cout << "Timer is running. Stop the current session first.\n";
        return;
    }


    std::string taskDescription;
    int sessionDuration;

    std::cout << "Description: ";
    std::cin.ignore();
    std::getline(std::cin, taskDescription);

    std::cout << "Focus time: ";
    std::cin >> sessionDuration; // проверка

    Session currentSession(taskDescription, sessionDuration);

    timer.start(currentSession, [this, currentSession](Session& s) 
{
    statistics.recordSession(s, "Focus_Statistics.txt");
}); 
}





void UI::pauseFocusSession()
{
    timer.pause();
}

void UI::resumeFocusSession()
{
    timer.resume();
}


void UI::stopFocusSession()
{
    timer.stop();
}



void UI::showStatistics()
{
    statistics.printStatistics("Focus_Statistics.txt");
}





void UI::run()
{
    int operation;
    do
    {
        displayMenu();
        std::cout << "Choose the operation: ";
        std::cin >> operation; // проверка




        switch (operation) 
        {
        case 1:
            startFocusSession();
            break;
        case 2:
            pauseFocusSession();
            break;
        case 3:
            resumeFocusSession();
            break;
        case 4:
            stopFocusSession();
            break;
        case 5:
            showStatistics();
            break;
        case 6:
            statistics.saveStatisticsToFile("Focus_Statistics.txt");
            std::cout << "Exit." << std::endl;
            break;
        default:
            std::cout << "Incorrect input." << std::endl;
        }
    } while (operation != 6);

    





}


