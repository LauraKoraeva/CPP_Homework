#include <iostream>
#include "window.h"
#include "utility.h"

int main()
{
    Window* window = new Window;

    int operation;
    while (true)
    {
        do
        {
            std::cout << "----------------------\n";
            std::cout << "Choose the operation:\n";
            std::cout << "1 - move\n";
            std::cout << "2 - resize\n";
            std::cout << "3 - display\n";
            std::cout << "4 - close\n";
            std::cout << "----------------------\n";
            std::cin >> operation;
        } while (!correctInput(operation));

        switch (operation)
        {
        case window->MOVE:
            window->move();
            break;
        case window->RESIZE:
            window->resize();
            break;
        case window->DISPLAY:
            window->display();
            break;
        case window->CLOSE:
            delete window;
            return 0;
        default:
            std::cout << "No such operation!\n";
        }
    }
}