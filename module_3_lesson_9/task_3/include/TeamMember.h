#pragma once
#include <string>
#include "Employee.h"

class TeamMember : public Employee
{
private:
    std::string workStatus;
public:
    TeamMember(std::string inName);

    void setWorkStatus(std::string inWorkStatus);

    std::string getWorkStatus() const;

    ~TeamMember() override;
};