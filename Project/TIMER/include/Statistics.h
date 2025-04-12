#pragma once
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include "Session.h"

class Statistics
{
private:

    std::vector<Session> sessions;

public:
    void recordSession(Session inSession, const std::string& fileName); // ///////////////////////// ()

    time_t stringToTimeT(const std::string& timeString, const std::string& format) const;

    void loadStatisticsFromFile(const std::string& fileName);

    std::string formatTimePoint(const std::chrono::system_clock::time_point& timePoint, const std::string& format) const;

    void saveStatisticsToFile(const std::string& fileName) const;
    
    void printStatistics(const std::string& fileName); //const;

    
};