#pragma once
#include <string>

class Employee
{
protected:
    std::string name;

public:
    Employee(std::string inName);

    void setName(std::string inName);

    std::string getName() const;

    virtual ~Employee();
};