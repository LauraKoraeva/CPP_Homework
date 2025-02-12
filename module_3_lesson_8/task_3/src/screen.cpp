#include <iostream>
#include "screen.h"

void Screen::setScreen()
{
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 80; ++j)
        {
            screen[i][j] = 0;
        }
    }
}

int Screen::getHeight() { return height; }
int Screen::getWidth() { return width; }

void Screen::showWindow(int inX, int inY, int end_x, int end_y)
{
    setScreen();
    for (int i = inX; i < end_x; ++i)
    {
        for (int j = inY; j < end_y; ++j)
        {
            screen[i][j] = 1;
        }
    }

    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 80; ++j)
        {
            std::cout << screen[i][j];
        }
        std::cout << '\n';
    }
}