#pragma once
#include <vector>
#include "Manager.h"
#include "Employee.h"

class ChiefExecutive : public Employee
{
private:
    std::vector<Manager*> managers;
    int teamsCount;

public:
    ChiefExecutive(std::string inName, int inTeamsCount);

    void setManagers();

    int assignTask() const;

    void workflow() const;

    ~ChiefExecutive() override;
};