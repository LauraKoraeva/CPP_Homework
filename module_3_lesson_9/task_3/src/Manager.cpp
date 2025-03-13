#include <iostream>
#include "Manager.h"
#include "WorkType.h"

Manager::Manager(std::string inName = "", int inID = 0, int inStaffNumber = 0)
    : Employee(inName), id(inID), staffNumber(inStaffNumber) 
{
    availableEmployeesCount = staffNumber;
    setTeam();
}

void Manager::setTeam()
{
    for (int i = 0; i < staffNumber; ++i)
    {
        std::cout << "Employee's name: ";
        std::string name;
        std::getline(std::cin, name);
        TeamMember* member = new TeamMember(name);
        team.push_back(member);
    }
}

int Manager::getAvailableEmployeesCount() const { return availableEmployeesCount; }
    
int Manager::divideTask(int inTask) const
{
    std::cout << name << " (manager) received the task.\n\n";
    std::srand(id + inTask);
    int subtasksNumber = std::rand() % staffNumber + 1;
    return subtasksNumber;
}
 
void Manager::distributeWork(int inSubtasksCount) const
{
    if (inSubtasksCount > availableEmployeesCount)
        inSubtasksCount = availableEmployeesCount;
    for (int i = 0; i < staffNumber; ++i)
    {
        if (team[i]->getWorkStatus() != "working")
        {
            team[i]->setWorkStatus("working");
            int workType = rand() % 3 + 1;
            std::cout << team[i]->getName() << " received task ";     //
            printWorkType(workType);
            std::cout << ".\n";
            --inSubtasksCount;
            --availableEmployeesCount;
            if (inSubtasksCount == 0)
                break;
        }
    }
}

Manager::~Manager() 
{
    for (const auto& member : team)
    {
        delete member;
    }
    team.clear();
}