//DRAFT

#include <iostream>

struct Point
{
    double x = 0;
    double y = 0;
};

void getPoint(Point& point)
{
    std::cout << "x: ";
    std::cin >> point.x;
    std::cout << "y: ";
    std::cin >> point.y;
}

void printPoint(const Point& point)
{
    std::cout << "(" << point.x << "; " << point.y << ")";
}

bool areEqual(const Point& point_1, const Point& point_2)
{
    if (point_1.x != point_2.x || point_1.y != point_2.y)
    {
        std::cout << "The location for the stitching is wrong.\n";
        return false;
    }
    else
        return true;
}


//

void scalpel(const Point& cutPoint_1, const Point& cutPoint_2)
{
    std::cout << "\nA cut was made between ";
    printPoint(cutPoint_1);
    std::cout << " and ";
    printPoint(cutPoint_2);
    std::cout << '\n';
}

void hemostat(const Point& point)
{
    std::cout << "\nHemostat was used at ";
    printPoint(point);
    std::cout << '\n';
}

void tweezers(const Point& point)
{
    std::cout << "\nA clamp was made at ";
    printPoint(point);
    std::cout << '\n';
}

void suture(const Point& point_1, const Point& point_2)
{
    std::cout << "\nStitches were made at ";
    printPoint(point_1);
    std::cout << " and ";
    printPoint(point_2);
    std::cout << '\n';
}


int main()
{
    Point cutPoint_1;
    Point cutPoint_2;
    Point point_3;
    Point point_4;
    std::cout << "Specify the location of the incision.\n";
    std::cout << "Beginning:\n";
    getPoint(cutPoint_1);
    std::cout << "End:\n";
    getPoint(cutPoint_2);

    scalpel(cutPoint_1, cutPoint_2);

    int choice;
    while (true)
    {
        std::cout << "\nChoose the next procedure:\n";
        std::cout << "1 - hemostat\n";
        std::cout << "2 - tweezers\n";
        std::cout << "3 - suture\n";
        std::cout << '\n';
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the location.\n";
            getPoint(point_3);
            hemostat(point_3);
            break;
        case 2:
            std::cout << "Enter the location.\n";
            getPoint(point_3);
            tweezers(point_3);
            break;
        case 3:
            do
            {
                std::cout << "Enter the location for the stitching.\n";
                getPoint(point_3);
                getPoint(point_4);
            } while (!areEqual(cutPoint_1, point_3) || !areEqual(cutPoint_2, point_4));

            suture(point_3, point_4);
            std::cout << "\nThe operation was completed successfully!\n";
            return 0;
        }
    }

}
