#pragma once

#include "Timer.h"
#include "Statistics.h"
#include "Session.h"

class UI
{
private:
    Timer& timer;
    Statistics& statistics;

    void displayMenu();
    void startFocusSession();
    void pauseFocusSession();
    void resumeFocusSession();
    void stopFocusSession();
    void showStatistics();

public:
    UI(Timer& inTimer, Statistics& inStatistics);

    void run();

};