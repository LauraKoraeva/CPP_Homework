#pragma once

class Screen
{
    int height = 50;
    int width = 80;
    int screen[50][80];
    
public:
    void setScreen();

    int getHeight();

    int getWidth();

    void showWindow(int inX, int inY, int end_x, int end_y);
};
