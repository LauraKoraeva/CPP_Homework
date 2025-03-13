#include "TeamMember.h"

TeamMember::TeamMember(std::string inName = "") : Employee(inName), workStatus("free") { }

void TeamMember::setWorkStatus(std::string inWorkStatus) { workStatus = inWorkStatus; }
    
std::string TeamMember::getWorkStatus() const { return workStatus; }

TeamMember::~TeamMember() { }