// Продвинутые темы и техники C++
// Урок 8. Введение в ООП. Часть 1

// Задание 3. Реализация программы управления окном рабочего стола

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

class Screen
{
    int m_height = 50;
    int m_width = 80;
    int m_screen[50][80];
public:
    void setScreen()
    {
        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 80; ++j)
            {
                m_screen[i][j] = 0;
            }
        }
    }

    int getHeight() { return m_height; }
    int getWidth() { return m_width; }

    void showWindow(int x, int y, int end_x, int end_y)
    {
        setScreen();
        for (int i = x; i < end_x; ++i)
        {
            for (int j = y; j < end_y; ++j)
            {
                m_screen[i][j] = 1;
            }
        }

        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 80; ++j)
            {
                std::cout << m_screen[i][j];
            }
            std::cout << '\n';
        }
    }
};

class Window
{
    int m_x = 0;
    int m_y = 0;
    int m_windowHeight = 10;
    int m_windowWidth = 10;

public:
    enum Operation
    {
        MOVE = 1,
        RESIZE,
        DISPLAY,
        CLOSE,
    };

    void set_x(int x, Screen* screen)
    {
        if (x < 0)
            m_x = 0;
        else if (x >= screen->getHeight())
            m_x = screen->getHeight();
        else
            m_x = x;
    }

    int get_x() { return m_x; }

    void set_y(int y, Screen* screen)
    {
        if (y < 0)
            m_y = 0;
        else if (y >= screen->getWidth())
            m_y = screen->getWidth();
        else
            m_y = y;
    }

    int get_y() { return m_y; }

    void setHeight(int height, Screen* screen)
    {
        if (height <= 0)
            m_windowHeight = 10;
        else if (height > screen->getHeight())
            m_windowHeight = screen->getHeight();
        else
            m_windowHeight = height;
    }

    int getHeight() { return m_windowHeight; }

    void setWidth(int width, Screen* screen)
    {
        if (width <= 0)
            m_windowWidth = 10;
        else if (width > screen->getWidth())
            m_windowWidth = screen->getWidth();
        else
            m_windowWidth = width;
    }

    int getWidth() { return m_windowWidth; }

    void move(Screen* screen)
    {
        int x, y;
        do
        {
            std::cout << "x offset: ";
            std::cin >> x;
        } while (!correctInput(x));
        do
        {
            std::cout << "y offset: ";
            std::cin >> y;
        } while (!correctInput(y));
        set_x(m_x + x, screen);
        set_y(m_y + y, screen);
        std::cout << "New coordinates: " << get_x() << ", " << get_y() << '\n';
    }

    void resize(Screen* screen)
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
        setHeight(height, screen);
        setWidth(width, screen);
        std::cout << "New size: " << getWidth() << " x " << getHeight() << '\n';
    }

    void display(Screen* screen)
    {
        int end_x = m_x + m_windowHeight;
        if (end_x >= screen->getHeight())
            end_x = screen->getHeight();

        int end_y = m_y + m_windowWidth;
        if (end_y >= screen->getWidth())
            end_y = screen->getWidth();

        screen->showWindow(m_x, m_y, end_x, end_y);
    }
};

int main()
{
    Screen* screen = new Screen;
    Window* window = new Window;
    screen->setScreen();

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
            window->move(screen);
            break;
        case window->RESIZE:
            window->resize(screen);
            break;
        case window->DISPLAY:
            window->display(screen);
            break;
        case window->CLOSE:
            delete screen;
            delete window;
            return 0;
        default:
            std::cout << "No such operation!\n";
        }
    }
}