#pragma once
#include "screen.h"

class Window
{
    int x;
    int y;
    int windowHeight;
    int windowWidth;
    Screen* screen;

public:
    enum Operation
    {
        MOVE = 1,
        RESIZE,
        DISPLAY,
        CLOSE,
    };
    
    Window();

    void set_x(int inX);

    int get_x();

    void set_y(int inY);

    int get_y();

    void setHeight(int inHeight);

    int getHeight();

    void setWidth(int inWidth);

    int getWidth();

    void move();

    void resize();

    void display();

    ~Window();
};
