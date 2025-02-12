#include <iostream>
#include "window.h"
#include "utility.h"

Window::Window()
    {
        x = 0;
        y = 0;
        windowHeight = 10;
        windowWidth = 10;
        screen = new Screen;
    }

void Window::set_x(int inX)
{
    if (inX < 0)
        x = 0;
    else if (inX >= screen->getHeight())
        x = screen->getHeight();
    else
        x = inX;
}

int Window::get_x() { return x; }

void Window::set_y(int inY)
{
    if (inY < 0)
        y = 0;
    else if (inY >= screen->getWidth())
        y = screen->getWidth();
    else
        y = inY;
}

int Window::get_y() { return y; }

void Window::setHeight(int inHeight)
{
    if (inHeight <= 0)
        windowHeight = 10;
    else if (inHeight > screen->getHeight())
        windowHeight = screen->getHeight();
    else
        windowHeight = inHeight;
}

int Window::getHeight() { return windowHeight; }

void Window::setWidth(int inWidth)
{
    if (inWidth <= 0)
        windowWidth = 10;
    else if (inWidth > screen->getWidth())
        windowWidth = screen->getWidth();
    else
        windowWidth = inWidth;
}

int Window::getWidth() { return windowWidth; }

void Window::move()
{
    int _x, _y;
    do
    {
        std::cout << "x offset: ";
        std::cin >> _x;
    } while (!correctInput(x));
    do
    {
        std::cout << "y offset: ";
        std::cin >> _y;
    } while (!correctInput(y));
    set_x(x + _x);
    set_y(y + _y);
    std::cout << "New coordinates: " << get_x() << ", " << get_y() << '\n';
}

void Window::resize()
{
    int height, width;
    do
    {
        std::cout << "height: ";
        std::cin >> height;
    } while (!correctInput(height));
    do
    {
        std::cout << "width: ";
        std::cin >> width;
    } while (!correctInput(width));
    setHeight(height);
    setWidth(width);
    std::cout << "New size: " << getWidth() << " x " << getHeight() << '\n';
}

void Window::display()
{
    int end_x = x + windowHeight;
    if (end_x >= screen->getHeight())
        end_x = screen->getHeight();

    int end_y = y + windowWidth;
    if (end_y >= screen->getWidth())
        end_y = screen->getWidth();

        screen->showWindow(x, y, end_x, end_y);
}

Window::~Window()
{
    delete screen;
}