#include "Employee.h"

Employee::Employee(std::string inName = "") : name(inName) { }

void Employee::setName(std::string inName) { name = inName; }

std::string Employee::getName() const { return name; }

Employee::~Employee() { }