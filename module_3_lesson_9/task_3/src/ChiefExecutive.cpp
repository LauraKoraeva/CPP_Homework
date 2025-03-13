#include <iostream>
#include <string>
#include <limits>
#include <numeric>
#include "ChiefExecutive.h"
#include "Utility.h"

ChiefExecutive::ChiefExecutive(std::string inName = "", int inTeamsCount = 0)
    : Employee(inName), teamsCount(inTeamsCount)
{
    setManagers();
}

void ChiefExecutive::setManagers()
{
    for (int i = 0; i < teamsCount; ++i)
    {
        std::cout << "\nTeam " << i + 1 << " manager's name: ";
        std::string managerName;
        std::getline(std::cin, managerName);

        int staffCount;
        do
        {
            std::cout << "Number of employees in Team " << i + 1 << ": ";
            std::cin >> staffCount;
        } while (!correctInput(staffCount));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Manager* manager = new Manager(managerName, i, staffCount);
        managers.push_back(manager);
    }
}

int ChiefExecutive::assignTask() const
{
    int task;
    do
    {
        static int teamNumber = 1;
        std::cout << "\nAssign a task to Team " << teamNumber << ": ";
        std::cin >> task;
        ++teamNumber;
        if (teamNumber > teamsCount)
            teamNumber = 1;
    } while (!correctInput(task));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return task;
}

void ChiefExecutive::workflow() const
{
    while (true)
    {
        int availableEmployeesCount = 0;
        for (int i = 0; i < teamsCount; ++i)
        {
            if (managers[i]->getAvailableEmployeesCount() != 0)
            {
                managers[i]->distributeWork(managers[i]->divideTask(assignTask()));
            }
            availableEmployeesCount += (managers[i]->getAvailableEmployeesCount());
        }
        if (availableEmployeesCount == 0)
        {
            std::cout << "\nEveryone is busy with work.\n";
            break;
        }
    }
}

ChiefExecutive::~ChiefExecutive() 
{
    for (const auto& manager : managers)
    {
        delete manager;
    }
    managers.clear();
}