// Продвинутые темы и техники C++
// Урок 3. Структуры данных

// 2. Модель данных для посёлка

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <numeric>

enum BuildingType
{
    HOUSE = 1,
    GARAGE,
    BARN,
    BATHHOUSE,
};

enum RoomType
{
    BEDROOM = 1,
    BATHROOM,
    NURSERY,
    LIVINGROOM,
    KITCHEN,
};

struct Room
{
    int type;
    double roomSquare;
};

struct Floor
{
    int number;
    double ceilingHeights;
    int roomsNumber;
    std::vector<Room> rooms;
};

struct House
{
    int floorsNumber;
    std::vector<Floor> floors;
};

struct Building
{
    int type;
    double buildingSquare;
    bool houseStove;
    bool bathStove;
    House house;
};

struct LandArea
{
    int landAreaID;
    double plotSquare;
    int buildingsNumber;
    std::vector<Building> buildings;

};

struct Village
{
    std::string name;
    int areasNumber;
    double villageSquare;
    std::vector<LandArea> areas;
};

bool correctInt(int input)
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

bool correctDouble(double input)
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

void printBuilding(int a)
{
    switch (a)
    {
    case 1:
        std::cout << "House ";
        break;
    case 2:
        std::cout << "Garage ";
        break;
    case 3:
        std::cout << "Barn ";
        break;
    case 4:
        std::cout << "Bathhouse ";
        break;
    }
}

void printRoom(int a)
{
    switch (a)
    {
    case 1:
        std::cout << "Bedroom ";
        break;
    case 2:
        std::cout << "Bathroom ";
        break;
    case 3:
        std::cout << "Nursery ";
        break;
    case 4:
        std::cout << "Living room ";
        break;
    case 5:
        std::cout << "Kitchen ";
        break;
    }
}

void printInfo(Village& village)
{
    std::cout << "\n___________________________________________________\n";
    std::cout << "Village name: " << village.name << "\t\tSq Ft: " << village.villageSquare << 
        "\tNumber of plots: " << village.areasNumber << '\n';
    for (int i = 0; i < village.areasNumber; ++i)
    {
        std::cout << "\nPLOT " << i + 1 << "\t\tSq Ft: " << village.areas[i].plotSquare << 
            "\tNumber of buildings: " << village.areas[i].buildingsNumber << '\n';
        for (int j = 0; j < village.areas[i].buildingsNumber; ++j)
        {
            std::cout << '\n';
            printBuilding(village.areas[i].buildings[j].type);
            std::cout << "\t\tSq Ft: " << village.areas[i].buildings[j].buildingSquare;

            switch (village.areas[i].buildings[j].type)
            {
            case 1:
                std::cout << "\tNumber of floors: " << village.areas[i].buildings[j].house.floorsNumber << '\n';
                for (int k = 0; k < village.areas[i].buildings[j].house.floorsNumber; ++k)
                {
                    std::cout << "\nFLOOR " << k + 1 << "\t\tCeiling height: " << village.areas[i].buildings[j].house.floors[k].ceilingHeights <<
                        "\tNumber of rooms: " << village.areas[i].buildings[j].house.floors[k].roomsNumber << '\n';

                    for (int m = 0; m < village.areas[i].buildings[j].house.floors[k].roomsNumber; ++m)
                    {

                        printRoom(village.areas[i].buildings[j].house.floors[k].rooms[m].type);
                        std::cout << "\tSq Ft: " << village.areas[i].buildings[j].house.floors[k].rooms[m].roomSquare << '\n';
                    }
                }
                std::cout << '\n';
                if (village.areas[i].buildings[j].houseStove)
                    std::cout << "Stove: yes\n";
                else
                    std::cout << "Stove: no\n";
                break;
            case 4:
                if (village.areas[i].buildings[j].houseStove)
                    std::cout << "\tStove: yes\n";
                else
                    std::cout << "\tStove: no\n";
                break;
            }
        }
        std::cout << '\n';
    }
}

void calculateLotCoverage(Village& village)
{
    double buildingArea = 0;
    for (int i = 0; i < village.areasNumber; ++i)
    {

        for (int j = 0; j < village.areas[i].buildingsNumber; ++j)
        {
            buildingArea += village.areas[i].buildings[j].buildingSquare;
        }
    }
    double lotCoverage = buildingArea / village.villageSquare * 100;
    std::cout << std::setprecision(4);
    std::cout << "Lot coverage: " << lotCoverage << '\n';
}

int main()
{
    Village village;
    std::cout << "Village name: ";
    std::getline(std::cin, village.name);
    std::cout << "Sq Ft: ";
    do
    {
        std::cin >> village.villageSquare;
    } while (!correctDouble(village.villageSquare));
    std::cout << "Number of plots in the village: ";
    do
    {
        std::cin >> village.areasNumber;
    } while (!correctInt(village.areasNumber));

    for (int i = 0; i < village.areasNumber; ++i)
    {
        std::cout << "\nPLOT " << i + 1 << '\n';
        LandArea a;
        village.areas.push_back(a);
        village.areas[i].landAreaID = i + 1;
        std::cout << "Sq Ft: ";
        do
        {
            std::cin >> village.areas[i].plotSquare;
        } while (!correctDouble(village.areas[i].plotSquare));
        std::cout << "Number of buildings on the plot: ";
        do
        {
            std::cin >> village.areas[i].buildingsNumber;
        } while (!correctInt(village.areas[i].buildingsNumber));

        for (int j = 0; j < village.areas[i].buildingsNumber; ++j)
        {
            std::cout << "\nBUILDING " << j + 1 << '\n';
            Building b;
            village.areas[i].buildings.push_back(b);
            std::cout << '\n';
            std::cout << "1 - house\n";
            std::cout << "2 - garage\n";
            std::cout << "3 - barn\n";
            std::cout << "4 - bathhouse\n";
            std::cout << "\nType of the building: ";
            do
            {
                std::cin >> village.areas[i].buildings[j].type;
            } while (!correctInt(village.areas[i].buildings[j].type));
            std::cout << "Sq Ft: ";
            do
            {
                std::cin >> village.areas[i].buildings[j].buildingSquare;
            } while (!correctDouble(village.areas[i].buildings[j].buildingSquare));

            std::string answer1;
            switch (village.areas[i].buildings[j].type)
            {
            case 1:
                std::cout << "Number of floors: ";
                do
                {
                    std::cin >> village.areas[i].buildings[j].house.floorsNumber;
                } while (!correctInt(village.areas[i].buildings[j].house.floorsNumber));

                for (int k = 0; k < village.areas[i].buildings[j].house.floorsNumber; ++k)
                {
                    std::cout << "\nFLOOR " << k + 1 << '\n';
                    Floor f;
                    village.areas[i].buildings[j].house.floors.push_back(f);
                    village.areas[i].buildings[j].house.floors[k].number = k;
                    std::cout << "Ceiling height: ";
                    do
                    {
                        std::cin >> village.areas[i].buildings[j].house.floors[k].ceilingHeights;
                    } while (!correctDouble(village.areas[i].buildings[j].house.floors[k].ceilingHeights));

                    std::cout << "Number of rooms: ";
                    do
                    {
                        std::cin >> village.areas[i].buildings[j].house.floors[k].roomsNumber;
                    } while (!correctInt(village.areas[i].buildings[j].house.floors[k].roomsNumber));

                    std::cout << '\n';
                    std::cout << "1 - bedroom\n";
                    std::cout << "2 - bathroom\n";
                    std::cout << "3 - nursery\n";
                    std::cout << "4 - living room\n";
                    std::cout << "5 - kitchen\n";
                    for (int m = 0; m < village.areas[i].buildings[j].house.floors[k].roomsNumber; ++m)
                    {
                        Room r;
                        village.areas[i].buildings[j].house.floors[k].rooms.push_back(r);
                        std::cout << "\nROOM " << m + 1 << '\n';

                        std::cout << "Type of the room: ";
                        do
                        {
                            std::cin >> village.areas[i].buildings[j].house.floors[k].rooms[m].type;
                        } while (!correctInt(village.areas[i].buildings[j].house.floors[k].rooms[m].type));
                        std::cout << "Sq Ft: ";
                        do
                        {
                            std::cin >> village.areas[i].buildings[j].house.floors[k].rooms[m].roomSquare;
                        } while (!correctDouble(village.areas[i].buildings[j].house.floors[k].rooms[m].roomSquare));

                    }
                }
                std::cout << "\nIs there a stove in the house? ";
                std::cin >> answer1;
                if (answer1 == "yes")
                    village.areas[i].buildings[j].houseStove = true;
                else
                    village.areas[i].buildings[j].houseStove = false;
                break;
            case 4:
                std::cout << "Is there a stove in the bathhouse? ";
                std::string answer2;
                std::cin >> answer2;
                if (answer2 == "yes")
                    village.areas[i].buildings[j].bathStove = true;
                else
                    village.areas[i].buildings[j].bathStove = false;
                break;
            }
        }
    }
    printInfo(village);

    std::cout << "\n\n";

    calculateLotCoverage(village);

    return 0;
}
