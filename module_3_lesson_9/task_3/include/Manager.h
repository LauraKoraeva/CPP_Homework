#pragma once
#include <vector>
#include <string>
#include "TeamMember.h"
#include "Employee.h"

class Manager : public Employee
{
private:
    int id;
    int staffNumber;
    std::vector<TeamMember*> team;
    mutable int availableEmployeesCount;

public:
    Manager(std::string inName, int inID, int inStaffNumber);

    void setTeam();

    int getAvailableEmployeesCount() const;
    
    int divideTask(int inTask) const;
 
    void distributeWork(int inSubtasksCount) const;

    ~Manager() override;
};